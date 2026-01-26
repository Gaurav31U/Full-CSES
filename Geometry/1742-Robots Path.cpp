#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Segment {
    int id;
    ll x1, y1, x2, y2; 
    ll min_x() const { return min(x1, x2); }
    ll max_x() const { return max(x1, x2); }
    ll min_y() const { return min(y1, y2); }
    ll max_y() const { return max(y1, y2); }
    bool is_vert() const { return x1 == x2; }
    ll len() const { return max_x() - min_x() + max_y() - min_y(); }
};

int n;
vector<Segment> segs;
vector<ll> y_uniques; 
int max_y_rank;
vector<int> bit;
void bit_update(int idx, int val) {
    for(; idx <= max_y_rank; idx += idx&-idx) bit[idx] += val;
}
int bit_query(int idx) {
    int s = 0;
    for(; idx > 0; idx -= idx&-idx) s += bit[idx];
    return s;
}
int get_y_rank(ll y) {
    return lower_bound(y_uniques.begin(), y_uniques.end(), y) - y_uniques.begin() + 1;
}
struct Event {
    ll x;
    int type;
    int y_rank1, y_rank2;
    bool operator<(const Event& o) const {
        if(x != o.x) return x < o.x;
        return type < o.type;
    }
};
struct Interval {
    ll l, r; 
    int id;
};
bool has_intersection(int k) {
    vector<pair<ll, Interval>> v_gr, h_gr;
    v_gr.reserve(k + 1); h_gr.reserve(k + 1);

    long long joints = 0;

    for(int i = 0; i <= k; ++i) {
        if (i < k) {
             if (segs[i].is_vert() != segs[i+1].is_vert()) joints++;
        }
        
        if (segs[i].is_vert()) {
            v_gr.push_back({segs[i].x1, {segs[i].min_y(), segs[i].max_y(), i}});
        } else {
            h_gr.push_back({segs[i].y1, {segs[i].min_x(), segs[i].max_x(), i}});
        }
    }

    auto check_intervals = [&](vector<pair<ll, Interval>>& group) {
        if (group.empty()) return false;
        sort(group.begin(), group.end(), [](const pair<ll, Interval>& a, const pair<ll, Interval>& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second.l < b.second.l;
        });

        for (size_t i = 0; i + 1 < group.size(); ++i) {
            if (group[i].first != group[i+1].first) continue;
            if (group[i].second.r >= group[i+1].second.l) {
                bool adjacent = (abs(group[i].second.id - group[i+1].second.id) == 1);
                if (adjacent) {
                    ll overlap_len = min(group[i].second.r, group[i+1].second.r) - group[i+1].second.l;
                    if (overlap_len > 0) return true;
                }
                else {
                    return true;
                }
            }
        }
        return false;
    };

    if (check_intervals(v_gr)) return true;
    if (check_intervals(h_gr)) return true;
    vector<Event> events;
    events.reserve(2 * k + 2);
    
    for (int i = 0; i <= k; ++i) {
        if (segs[i].is_vert()) {
            events.push_back({segs[i].x1, 1, get_y_rank(segs[i].min_y()), get_y_rank(segs[i].max_y())});
        } else {
            int y_r = get_y_rank(segs[i].y1);
            events.push_back({segs[i].min_x(), 0, y_r, 0});
            events.push_back({segs[i].max_x(), 2, y_r, 0});
        }
    }
    sort(events.begin(), events.end());
    
    long long hits = 0;
    for(const auto& e : events) {
        if (e.type == 0) { 
            bit_update(e.y_rank1, 1);
        } else if (e.type == 2) {
            bit_update(e.y_rank1, -1);
        } else { // Query
            hits += (bit_query(e.y_rank2) - bit_query(e.y_rank1 - 1));
        }
    }
    return hits > joints;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;
    segs.resize(n);
    y_uniques.reserve(2*n + 10);
    y_uniques.push_back(0);

    ll curX = 0, curY = 0;
    for(int i=0; i<n; ++i) {
        char d; ll l;
        cin >> d >> l;
        segs[i].id = i;
        segs[i].x1 = curX; segs[i].y1 = curY;
        if(d=='U') curY += l;
        else if(d=='D') curY -= l;
        else if(d=='L') curX -= l;
        else if(d=='R') curX += l;
        segs[i].x2 = curX; segs[i].y2 = curY;

        y_uniques.push_back(segs[i].y1);
        y_uniques.push_back(segs[i].y2);
    }
    sort(y_uniques.begin(), y_uniques.end());
    y_uniques.erase(unique(y_uniques.begin(), y_uniques.end()), y_uniques.end());
    max_y_rank = y_uniques.size();
    bit.assign(max_y_rank + 5, 0);
    int low = 0, high = n - 1;
    int k_found = -1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        if (has_intersection(mid)) {
            k_found = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    ll total_dist = 0;
    
    if (k_found == -1) {
        for(const auto& s : segs) total_dist += s.len();
        cout << total_dist << "\n";
    } else {
        for(int i = 0; i < k_found; ++i) total_dist += segs[i].len();
        ll min_overlap = -1; 
        
        Segment cur = segs[k_found];
        
        auto update = [&](ll d) {
            if (min_overlap == -1 || d < min_overlap) min_overlap = d;
        };
        
        for(int j=0; j<k_found; ++j) {
            Segment prev = segs[j];
            bool sameDir = (cur.is_vert() == prev.is_vert());
            
            if (sameDir) {
                if ((cur.is_vert() && cur.x1 == prev.x1) || (!cur.is_vert() && cur.y1 == prev.y1)) {
                     ll l1 = cur.is_vert() ? cur.min_y() : cur.min_x();
                     ll r1 = cur.is_vert() ? cur.max_y() : cur.max_x();
                     ll l2 = prev.is_vert() ? prev.min_y() : prev.min_x();
                     ll r2 = prev.is_vert() ? prev.max_y() : prev.max_x();
                     
                     ll over_l = max(l1, l2);
                     ll over_r = min(r1, r2);
                     
                     if (over_l <= over_r) {
                         bool adj = (j == k_found - 1);
                         if (!adj || (over_r - over_l > 0)) {
                             ll start = cur.is_vert() ? cur.y1 : cur.x1;
                             ll d = 0;
                             if (start >= over_l && start <= over_r) d = 0;
                             else d = min(abs(start - over_l), abs(start - over_r));
                             update(d);
                         }
                     }
                }
            } 
            else {
                Segment V = cur.is_vert() ? cur : prev;
                Segment H = cur.is_vert() ? prev : cur;
                
                if (V.x1 >= H.min_x() && V.x1 <= H.max_x() && H.y1 >= V.min_y() && H.y1 <= V.max_y()) {
                    if (j == k_found - 1) {
                    } else {
                         ll d = abs(cur.x1 - V.x1) + abs(cur.y1 - H.y1);
                         update(d);
                    }
                }
            }
        }
        cout << total_dist + min_overlap << "\n";
    }

    return 0;
}