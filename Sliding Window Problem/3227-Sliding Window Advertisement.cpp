#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Line {
    ll m, c;
    ll eval(int x) { return m * x + c; }
};

const int MAXN = 200005;

Line tree[4 * MAXN];
void build(int node, int start, int end) {
    tree[node] = {0, 0}; 
    if (start == end) return;
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
}

void add_line(int node, int start, int end, Line v) {
    int mid = (start + end) / 2;
    bool left = v.eval(start) > tree[node].eval(start);
    bool mid_val = v.eval(mid) > tree[node].eval(mid);

    if (mid_val) {
        swap(tree[node], v);
    }
    if (start == end) return;
    
    if (left != mid_val) {
        add_line(2 * node, start, mid, v);
    } else {
        add_line(2 * node + 1, mid + 1, end, v);
    }
}
void add_segment(int node, int start, int end, int l, int r, Line v) {
    if (l > end || r < start) return;
    if (l <= start && end <= r) {
        add_line(node, start, end, v);
        return;
    }
    int mid = (start + end) / 2;
    add_segment(2 * node, start, mid, l, r, v);
    add_segment(2 * node + 1, mid + 1, end, l, r, v);
}

ll query(int node, int start, int end, int x) {
    ll val = tree[node].eval(x);
    if (start == end) return val;
    int mid = (start + end) / 2;
    if (x <= mid) return max(val, query(2 * node, start, mid, x));
    else return max(val, query(2 * node + 1, mid + 1, end, x));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> l_bound(n), r_bound(n);
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && h[s.top()] >= h[i]) s.pop();
        l_bound[i] = (s.empty()) ? 0 : s.top() + 1;
        s.push(i);
    }
    
    while (!s.empty()) s.pop();
    
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && h[s.top()] >= h[i]) s.pop();
        r_bound[i] = (s.empty()) ? n - 1 : s.top() - 1;
        s.push(i);
    }

    int max_window_idx = n - k;
    build(1, 0, max_window_idx);

    auto get_area_at_j = [&](int idx, int j) -> ll {
        int overlap_start = max(l_bound[idx], j);
        int overlap_end = min(r_bound[idx], j + k - 1);
        int len = max(0, overlap_end - overlap_start + 1);
        return (ll)h[idx] * len;
    };

    for (int i = 0; i < n; i++) {
        int start_j = max(0, i - k + 1);
        int end_j = min(max_window_idx, i);
        
        if (start_j > end_j) continue;

        int cp1 = l_bound[i];
        int cp2 = r_bound[i] - k + 1;

        vector<int> pts = {start_j, end_j + 1};
        if (cp1 > start_j && cp1 <= end_j + 1) pts.push_back(cp1);
        if (cp2 > start_j && cp2 <= end_j + 1) pts.push_back(cp2);
        
        sort(pts.begin(), pts.end());
        pts.erase(unique(pts.begin(), pts.end()), pts.end());

        for (size_t p = 0; p < pts.size() - 1; p++) {
            int s_seg = pts[p];
            int e_seg = pts[p+1] - 1;
            
            ll val1 = get_area_at_j(i, s_seg);
            ll val2 = get_area_at_j(i, e_seg);
            
            Line segment;
            if (s_seg == e_seg) {
                segment = {0, val1};
            } else {
                segment.m = (val2 - val1) / (e_seg - s_seg);
                segment.c = val1 - segment.m * s_seg;
            }
            
            add_segment(1, 0, max_window_idx, s_seg, e_seg, segment);
        }
    }
    for (int j = 0; j <= max_window_idx; j++) {
        cout << query(1, 0, max_window_idx, j) << (j == max_window_idx ? "" : " ");
    }
    cout << "\n";

    return 0;
}