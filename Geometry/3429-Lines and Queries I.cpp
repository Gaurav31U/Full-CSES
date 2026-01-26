#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18; 
struct Line {
    ll m, c; 
    ll eval(ll x) const { return m * x + c; }
};
const int MAX_X = 100000;
const int TREE_SIZE = 400005;
Line tree[TREE_SIZE];
void init_tree() {
    for (int i = 0; i < TREE_SIZE; ++i) {
        tree[i] = {0, -INF};
    }
}
void add_line(int node, int start, int end, Line new_line) {
    int mid = start + (end - start) / 2;
    bool better_at_mid = new_line.eval(mid) > tree[node].eval(mid);
    if (better_at_mid) {
        swap(tree[node], new_line);
    }
    if (start == end) {
        return;
    }
    if (new_line.eval(start) > tree[node].eval(start)) {
        add_line(2 * node, start, mid, new_line);
    } else if (new_line.eval(end) > tree[node].eval(end)) {
        add_line(2 * node + 1, mid + 1, end, new_line);
    }
}
ll query(int node, int start, int end, int x) {
    if (start == end) {
        return tree[node].eval(x);
    }
    int mid = start + (end - start) / 2;
    ll current_val = tree[node].eval(x);
    if (x <= mid) {
        return max(current_val, query(2 * node, start, mid, x));
    } else {
        return max(current_val, query(2 * node + 1, mid + 1, end, x));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        init_tree();
        
        while (n--) {
            int type;
            cin >> type;
            if (type == 1) {
                ll a, b;
                cin >> a >> b;
                add_line(1, 0, MAX_X, {a, b});
            } else {
                int x;
                cin >> x;
                cout << query(1, 0, MAX_X, x) << "\n";
            }
        }
    }
    return 0;
}