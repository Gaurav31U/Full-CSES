#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18; 
struct Line {
    ll m, c; 
    ll eval(ll x) const { return m * x + c; }
};
const int MAX_COORD = 100005;
Line tree[4 * MAX_COORD];
void add_line(int node, int L, int R, int ql, int qr, Line new_line) {
    if (ql > R || qr < L) return;
    int mid = L + (R - L) / 2;
    if (ql <= L && R <= qr) {
        bool better_at_mid = new_line.eval(mid) > tree[node].eval(mid);
        if (better_at_mid) {
            swap(tree[node], new_line);
        }
        if (new_line.c == -INF) return;
        if (L == R) return;
        if (new_line.eval(L) > tree[node].eval(L)) {
            add_line(2 * node, L, mid, ql, qr, new_line);
        } else if (new_line.eval(R) > tree[node].eval(R)) {
            add_line(2 * node + 1, mid + 1, R, ql, qr, new_line);
        }
        return;
    }
    add_line(2 * node, L, mid, ql, qr, new_line);
    add_line(2 * node + 1, mid + 1, R, ql, qr, new_line);
}
ll query(int node, int L, int R, int x) {
    ll val = tree[node].eval(x);
    if (L == R) return val;
    int mid = L + (R - L) / 2;
    if (x <= mid) {
        return max(val, query(2 * node, L, mid, x));
    } else {
        return max(val, query(2 * node + 1, mid + 1, R, x));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        for(int i = 0; i < 4 * MAX_COORD; ++i) {
            tree[i] = {0, -INF};
        }
        while (n--) {
            int type;
            cin >> type;
            if (type == 1) {
                ll a, b; 
                int l, r;
                cin >> a >> b >> l >> r;
                l = max(0, l); 
                r = min(100000, r);
                if (l <= r) {
                    add_line(1, 0, 100000, l, r, {a, b});
                }
            } else {
                int x;
                cin >> x;
                ll result = query(1, 0, 100000, x);
                if (result < -1e18) {
                    cout << "NO\n";
                } else {
                    cout << result << "\n";
                }
            }
        }
    }
    return 0;
}