#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Line {
    ll k, b;
    bool active; 
    ll eval(int x) const {
        if (!active) return -1;
        return k * (ll)x + b;
    }
};
const int MAX_M = 100005;
Line tree[4 * MAX_M];
void build(int node, int L, int R) {
    tree[node] = {0, -1, false};
    if (L == R) return;
    int mid = (L + R) >> 1;
    build(node << 1, L, mid);
    build((node << 1) | 1, mid + 1, R);
}
void add_line_to_node(int node, int L, int R, Line new_line) {
    if (!tree[node].active) {
        tree[node] = new_line;
        return;
    }
    int mid = (L + R) >> 1;
    bool better_at_mid = new_line.eval(mid) > tree[node].eval(mid);
    if (better_at_mid) {
        swap(tree[node], new_line);
    }
    if (L == R) return;
    if (new_line.eval(L) > tree[node].eval(L)) {
        add_line_to_node(node << 1, L, mid, new_line);
    } else if (new_line.eval(R) > tree[node].eval(R)) {
        add_line_to_node((node << 1) | 1, mid + 1, R, new_line);
    }
}
void add_segment(int node, int L, int R, int l, int r, Line line) {
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        add_line_to_node(node, L, R, line);
        return;
    }
    int mid = (L + R) >> 1;
    add_segment(node << 1, L, mid, l, r, line);
    add_segment((node << 1) | 1, mid + 1, R, l, r, line);
}
ll query(int node, int L, int R, int x) {
    ll val = tree[node].eval(x);
    if (L == R) return val;
    int mid = (L + R) >> 1;
    if (x <= mid) {
        return max(val, query(node << 1, L, mid, x));
    } else {
        return max(val, query((node << 1) | 1, mid + 1, R, x));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    build(1, 0, m);
    for (int i = 0; i < n; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll k = (y2 - y1) / (x2 - x1);
        ll b = y1 - k * x1;

        Line l = {k, b, true};
        add_segment(1, 0, m, (int)x1, (int)x2, l);
    }

    for (int x = 0; x <= m; ++x) {
        cout << query(1, 0, m, x) << (x == m ? "" : " ");
    }
    cout << "\n";

    return 0;
}