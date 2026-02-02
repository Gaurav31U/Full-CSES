#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18; 
const int MAXC = 1000005; 
struct Line {
    ll m, c;
    ll eval(int x) { return m * x + c; }
};
Line tree[4 * MAXC];
void init_tree(int node, int l, int r) {
    tree[node] = {0, INF};
    if (l == r) return;
    int mid = (l + r) / 2;
    init_tree(2 * node, l, mid);
    init_tree(2 * node + 1, mid + 1, r);
}
void add_line(Line newLine, int node, int l, int r) {
    int mid = (l + r) / 2;
    bool mid_better = newLine.eval(mid) < tree[node].eval(mid);
    if (mid_better) {
        swap(tree[node], newLine);
    }
    
    if (l == r) return;
    if (newLine.eval(l) < tree[node].eval(l)) {
        add_line(newLine, 2 * node, l, mid);
    } else if (newLine.eval(r) < tree[node].eval(r)) {
        add_line(newLine, 2 * node + 1, mid + 1, r);
    }
}
ll query(int x, int node, int l, int r) {
    ll val = tree[node].eval(x);
    if (l == r) return val;
    int mid = (l + r) / 2;
    if (x <= mid) {
        return min(val, query(x, 2 * node, l, mid));
    } else {
        return min(val, query(x, 2 * node + 1, mid + 1, r));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x; 
    if (cin >> n >> x) {
        vector<ll> s(n);
        vector<ll> f(n);

        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++) cin >> f[i];
        init_tree(1, 1, MAXC);
        add_line({x, 0}, 1, 1, MAXC);

        ll current_min_time = 0;

        for (int i = 0; i < n; i++) {
            current_min_time = query(s[i], 1, 1, MAXC);
            if (i == n - 1) break;
            add_line({f[i], current_min_time}, 1, 1, MAXC);
        }
        cout << current_min_time << endl;
    }
    return 0;
}