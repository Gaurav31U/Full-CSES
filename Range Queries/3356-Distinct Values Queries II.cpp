#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
int tree[4 * MAXN];
int n;
int arr[MAXN];
map<int, set<int>> positions;
void update_tree(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update_tree(2 * node, start, mid, idx, val);
    else
        update_tree(2 * node + 1, mid + 1, end, idx, val);
    
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query_tree(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return max(query_tree(2 * node, start, mid, l, r),
               query_tree(2 * node + 1, mid + 1, end, l, r));
}
void update_index_prev(int idx, int prev_idx) {
    update_tree(1, 1, n, idx, prev_idx);
}
void modify_value(int idx, int new_val) {
    int old_val = arr[idx];
    if (old_val == new_val) return;
    auto& old_set = positions[old_val];
    auto it = old_set.find(idx);
    
    int prev_pos_old = 0;
    if (it != old_set.begin()) {
        prev_pos_old = *prev(it);
    }
    int next_pos_old = 0;
    if (next(it) != old_set.end()) {
        next_pos_old = *next(it);
    }
    old_set.erase(it);
    if (old_set.empty()) positions.erase(old_val);
    if (next_pos_old != 0) {
        update_index_prev(next_pos_old, prev_pos_old);
    }
    arr[idx] = new_val;
    positions[new_val].insert(idx);
    auto& new_set = positions[new_val];
    it = new_set.find(idx);    
    int prev_pos_new = 0;
    if (it != new_set.begin()) {
        prev_pos_new = *prev(it);
    }
    int next_pos_new = 0;
    if (next(it) != new_set.end()) {
        next_pos_new = *next(it);
    }
    update_index_prev(idx, prev_pos_new);
    if (next_pos_new != 0) {
        update_index_prev(next_pos_new, idx);
    }
}
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if (!(cin >> n >> q)) return 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        positions[arr[i]].insert(i);
    }
    for (auto const& [val, indices] : positions) {
        int last_pos = 0;
        for (int idx : indices) {
            update_index_prev(idx, last_pos);
            last_pos = idx;
        }
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            modify_value(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            if (query_tree(1, 1, n, a, b) < a) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}