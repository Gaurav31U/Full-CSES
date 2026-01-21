#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 200005; 
const int MAX_NODES = MAXN * 2 + MAXN * 25;
struct Node {
    ll sum;
    int left; 
    int right;
} tree[MAX_NODES];
int node_cnt = 0;
int n;         
vector<int> arr_roots;
int new_node(ll sum, int left, int right) {
    int id = ++node_cnt;
    tree[id].sum = sum;
    tree[id].left = left;
    tree[id].right = right;
    return id;
}
int copy_node(int id) {
    return new_node(tree[id].sum, tree[id].left, tree[id].right);
}
int build(const vector<int>& initial_data, int tl, int tr) {
    if (tl == tr) {
        return new_node(initial_data[tl], 0, 0);
    }
    int tm = (tl + tr) / 2;
    int left_child = build(initial_data, tl, tm);
    int right_child = build(initial_data, tm + 1, tr);
    return new_node(tree[left_child].sum + tree[right_child].sum, left_child, right_child);
}
int update(int node, int tl, int tr, int pos, int val) {
    int current = copy_node(node); 
    if (tl == tr) {
        tree[current].sum = val;
        return current;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        tree[current].left = update(tree[node].left, tl, tm, pos, val);
    } else {
        tree[current].right = update(tree[node].right, tm + 1, tr, pos, val);
    }
    tree[current].sum = tree[tree[current].left].sum + tree[tree[current].right].sum;
    return current;
}
ll query(int node, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[node].sum;
    int tm = (tl + tr) / 2;
    return query(tree[node].left, tl, tm, l, min(r, tm)) +
           query(tree[node].right, tm + 1, tr, max(l, tm + 1), r);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> n >> q)) return 0;
    vector<int> initial_data(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> initial_data[i];
    }
    arr_roots.push_back(0); 
    arr_roots.push_back(build(initial_data, 1, n));

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, a, x;
            cin >> k >> a >> x;
            arr_roots[k] = update(arr_roots[k], 1, n, a, x);
        } 
        else if (type == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            cout << query(arr_roots[k], 1, n, a, b) << "\n";
        } 
        else {
            int k;
            cin >> k;
            arr_roots.push_back(arr_roots[k]);
        }
    }
    return 0;
}