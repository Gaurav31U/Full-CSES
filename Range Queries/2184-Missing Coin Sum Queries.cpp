#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
const int MAX_NODES = MAXN * 25; 
struct Node {
    long long sum;
    int left;
    int right;
} tree[MAX_NODES];
int roots[MAXN]; 
int node_cnt = 0;
int n, q;
vector<int> distinct_values;
vector<int> x;
int build(int tl, int tr) {
    int id = ++node_cnt;
    tree[id].sum = 0;
    if (tl == tr) {
        tree[id].left = 0;
        tree[id].right = 0;
        return id;
    }
    int tm = (tl + tr) / 2;
    tree[id].left = build(tl, tm);
    tree[id].right = build(tm + 1, tr);
    return id;
}
int update(int prev_node, int tl, int tr, int pos_idx, int val) {
    int id = ++node_cnt;
    tree[id] = tree[prev_node];
    
    if (tl == tr) {
        tree[id].sum += val;
        return id;
    }
    
    int tm = (tl + tr) / 2;
    if (pos_idx <= tm) {
        tree[id].left = update(tree[prev_node].left, tl, tm, pos_idx, val);
    } else {
        tree[id].right = update(tree[prev_node].right, tm + 1, tr, pos_idx, val);
    }
    
    tree[id].sum = tree[tree[id].left].sum + tree[tree[id].right].sum;
    return id;
}
long long query(int node_r, int node_l, int tl, int tr, int k) {
    if (k < tl) return 0; 
    if (tr <= k) {
        return tree[node_r].sum - tree[node_l].sum;
    }
    int tm = (tl + tr) / 2;
    return query(tree[node_r].left, tree[node_l].left, tl, tm, k) + 
           query(tree[node_r].right, tree[node_l].right, tm + 1, tr, k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n >> q)) return 0;
    x.resize(n + 1);
    distinct_values.reserve(n);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        distinct_values.push_back(x[i]);
    }
    sort(distinct_values.begin(), distinct_values.end());
    distinct_values.erase(unique(distinct_values.begin(), distinct_values.end()), distinct_values.end());
    int m = distinct_values.size();
    if (m > 0) roots[0] = build(0, m - 1);
    else roots[0] = 0;
    for(int i = 1; i <= n; i++) {
        int rank = lower_bound(distinct_values.begin(), distinct_values.end(), x[i]) - distinct_values.begin();
        roots[i] = update(roots[i-1], 0, m - 1, rank, x[i]);
    }
    const long long INF_LIMIT = 2000000000LL;
    while(q--) {
        int a, b;
        cin >> a >> b;
        long long cur_ans = 1;
        while(true) {
            int limit_idx;
            if (cur_ans >= INF_LIMIT) {
                limit_idx = m - 1; 
            } else {
                auto it = upper_bound(distinct_values.begin(), distinct_values.end(), (int)cur_ans);
                limit_idx = (int)(it - distinct_values.begin()) - 1;
            }
            if (limit_idx < 0) {
                break; 
            }
            long long sum_in_range = query(roots[b], roots[a-1], 0, m - 1, limit_idx);
            if (sum_in_range >= cur_ans) {
                cur_ans = sum_in_range + 1;
            } else {
                break;
            }
        }
        cout << cur_ans << "\n";
    }
    return 0;
}