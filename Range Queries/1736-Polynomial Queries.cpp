#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
struct Node {
    ll sum;   
    ll lz_k; 
    ll lz_c; 
} tree[4 * MAXN];
int n;
ll sum_indices(int L, int R) {
    return (ll)(L + R) * (R - L + 1) / 2;
}
void push(int v, int tl, int tr) {
    if (tree[v].lz_k == 0 && tree[v].lz_c == 0) return;
    int tm = (tl + tr) / 2;
    int left = 2 * v;
    int right = 2 * v + 1;
    ll count_left = tm - tl + 1;
    tree[left].sum += tree[v].lz_k * sum_indices(tl, tm) + tree[v].lz_c * count_left;
    tree[left].lz_k += tree[v].lz_k;
    tree[left].lz_c += tree[v].lz_c;
    ll count_right = tr - tm; 
    tree[right].sum += tree[v].lz_k * sum_indices(tm + 1, tr) + tree[v].lz_c * count_right;
    tree[right].lz_k += tree[v].lz_k;
    tree[right].lz_c += tree[v].lz_c;
    tree[v].lz_k = 0;
    tree[v].lz_c = 0;
}
void update(int v, int tl, int tr, int l, int r, ll k, ll c) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[v].sum += k * sum_indices(tl, tr) + c * (tr - tl + 1);
        tree[v].lz_k += k;
        tree[v].lz_c += c;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), k, c);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, k, c);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
    }
}
ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[v].sum;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(r, tm)) +
           query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}
void build(const vector<ll>& a, int v, int tl, int tr) {
    tree[v].lz_k = 0;
    tree[v].lz_c = 0;
    if (tl == tr) {
        tree[v].sum = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> n >> q) {
        vector<ll> t(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
        }
        build(t, 1, 1, n);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int a, b;
                cin >> a >> b;
                update(1, 1, n, a, b, 1, 1 - a);
            } else {
                int a, b;
                cin >> a >> b;
                cout << query(1, 1, n, a, b) << "\n";
            }
        }
    }
    return 0;
}