#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int h[MAXN], n, q;
struct Node {
    int mx;
    int precalc; 
} tree[4 * MAXN];
int calc(int v, int l, int r, int threshold) {
    if (tree[v].mx <= threshold) return 0;
    if (l == r) return tree[v].mx > threshold;
    int mid = (l + r) / 2;
    if (tree[2 * v].mx <= threshold) {
        return calc(2 * v + 1, mid + 1, r, threshold);
    } else {
        return calc(2 * v, l, mid, threshold) + tree[v].precalc;
    }
}
void build(int v, int l, int r) {
    if (l == r) {
        tree[v].mx = h[l];
        tree[v].precalc = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    tree[v].mx = max(tree[2 * v].mx, tree[2 * v + 1].mx);
    tree[v].precalc = calc(2 * v + 1, mid + 1, r, tree[2 * v].mx);
}
int query(int v, int l, int r, int ql, int qr, int &running_max) {
    if (ql <= l && r <= qr) {
        int res = calc(v, l, r, running_max);
        running_max = max(running_max, tree[v].mx);
        return res;
    }
    int mid = (l + r) / 2;
    int res = 0;
    if (ql <= mid) res += query(2 * v, l, mid, ql, qr, running_max);
    if (qr > mid) res += query(2 * v + 1, mid + 1, r, ql, qr, running_max);
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> h[i];
    build(1, 1, n);   
    while (q--) {
        int a, b;
        cin >> a >> b;
        int running_max = 0; 
        cout << query(1, 1, n, a, b, running_max) << "\n";
    }
    return 0;
}