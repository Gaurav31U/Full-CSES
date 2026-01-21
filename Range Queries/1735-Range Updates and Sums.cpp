#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
struct Node {
    ll sum;
    ll lazy_set;
    ll lazy_add; 
} tree[4 * MAXN];
int n;
void push(int v, int tl, int tr) {
    if (tl == tr) return; 
    int tm = (tl + tr) / 2;
    int left = 2 * v;
    int right = 2 * v + 1;
    int len_left = tm - tl + 1;
    int len_right = tr - tm;
    if (tree[v].lazy_set != 0) {
        ll val = tree[v].lazy_set;
        tree[left].lazy_set = val;
        tree[left].lazy_add = 0;
        tree[left].sum = (ll)len_left * val;
        tree[right].lazy_set = val;
        tree[right].lazy_add = 0;
        tree[right].sum = (ll)len_right * val;
        tree[v].lazy_set = 0;
    }
    if (tree[v].lazy_add != 0) {
        ll val = tree[v].lazy_add;
        if (tree[left].lazy_set != 0) {
            tree[left].lazy_set += val; 
        } else {
            tree[left].lazy_add += val;
        }
        tree[left].sum += (ll)len_left * val;
        if (tree[right].lazy_set != 0) {
            tree[right].lazy_set += val;
        } else {
            tree[right].lazy_add += val;
        }
        tree[right].sum += (ll)len_right * val;

        tree[v].lazy_add = 0;
    }
}
void build(const vector<int>& a, int v, int tl, int tr) {
    tree[v].lazy_set = 0;
    tree[v].lazy_add = 0;
    if (tl == tr) {
        tree[v].sum = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
    }
}
void update_add(int v, int tl, int tr, int l, int r, int add_val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        if (tree[v].lazy_set != 0) {
            tree[v].lazy_set += add_val;
        } else {
            tree[v].lazy_add += add_val;
        }
        tree[v].sum += (ll)(r - l + 1) * add_val;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update_add(2 * v, tl, tm, l, min(r, tm), add_val);
        update_add(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add_val);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
    }
}
void update_set(int v, int tl, int tr, int l, int r, int set_val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[v].lazy_set = set_val;
        tree[v].lazy_add = 0;
        tree[v].sum = (ll)(r - l + 1) * set_val;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update_set(2 * v, tl, tm, l, min(r, tm), set_val);
        update_set(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, set_val);
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if (cin >> n >> q) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(a, 1, 1, n);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) { 
                int a_in, b_in, x;
                cin >> a_in >> b_in >> x;
                update_add(1, 1, n, a_in, b_in, x);
            } else if (type == 2) { // Set range
                int a_in, b_in, x;
                cin >> a_in >> b_in >> x;
                update_set(1, 1, n, a_in, b_in, x);
            } else { // Query Sum
                int a_in, b_in;
                cin >> a_in >> b_in;
                cout << query(1, 1, n, a_in, b_in) << "\n";
            }
        }
    }
    return 0;
}