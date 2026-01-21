#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    int sum, pref, suff, ans;
};
Node make_node(int v) {
    Node res;
    res.sum = v;
    res.pref = res.suff = res.ans = max(0LL, v);
    return res;
}
Node merge(Node l, Node r) {
    Node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    return res;
}
const int N = 200005;
int arr[N];
Node tree[4 * N];
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = make_node(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
Node query(int node, int start, int end, int l, int r) {
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    if (r <= mid) return query(2 * node, start, mid, l, r);
    if (l > mid) return query(2 * node + 1, mid + 1, end, l, r);
    Node left_res = query(2 * node, start, mid, l, mid);
    Node right_res = query(2 * node + 1, mid + 1, end, mid + 1, r);
    return merge(left_res, right_res);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b).ans << "\n";
    }
    return 0;
}