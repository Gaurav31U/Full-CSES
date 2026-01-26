#include <bits/stdc++.h>
using namespace std;
struct Event {
    int x;
    int type; 
    int y1, y2;
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};
struct Node {
    int cnt; 
    long long len; 
};
const int MAX_Y_NODES = 200005; 
Node tree[8 * MAX_Y_NODES];
vector<int> y_coords; 
void update_node(int node, int L, int R) {
    if (tree[node].cnt > 0) {
        tree[node].len = (long long)y_coords[R + 1] - y_coords[L];
    } else {
        if (L != R) {
            tree[node].len = tree[node * 2].len + tree[node * 2 + 1].len;
        } else {
            tree[node].len = 0;
        }
    }
}
void update(int node, int L, int R, int q_y1, int q_y2, int val) {
    if (q_y1 > R || q_y2 < L) return;
    
    if (q_y1 <= L && R <= q_y2) {
        tree[node].cnt += val;
        update_node(node, L, R);
        return;
    }

    int mid = L + (R - L) / 2;
    update(node * 2, L, mid, q_y1, q_y2, val);
    update(node * 2 + 1, mid + 1, R, q_y1, q_y2, val);
    
    update_node(node, L, R);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin >> n;
    vector<Event> events;
    y_coords.reserve(n * 2);
    events.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, 1, y1, y2});
        events.push_back({x2, -1, y1, y2});
        
        y_coords.push_back(y1);
        y_coords.push_back(y2);
    }
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    sort(events.begin(), events.end());
    long long total_area = 0;
    int max_idx = (int)y_coords.size() - 1; 
    for (size_t i = 0; i < events.size(); ++i) {
        if (i > 0) {
            long long dx = (long long)events[i].x - events[i-1].x;
            if (dx > 0) {
                total_area += dx * tree[1].len;
            }
        }
        int idx1 = lower_bound(y_coords.begin(), y_coords.end(), events[i].y1) - y_coords.begin();
        int idx2 = lower_bound(y_coords.begin(), y_coords.end(), events[i].y2) - y_coords.begin();
        if (idx1 < idx2) {
            update(1, 0, max_idx - 1, idx1, idx2 - 1, events[i].type);
        }
    }

    cout << total_area << "\n";

    return 0;
}