#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 200005;
vector<int> adj[MAXN];
int in[MAXN], out[MAXN];
int timer = 0;
long long current_values[MAXN];
long long bit[MAXN];
int n;
void dfs(int u, int p) {
    timer++;
    in[u] = timer;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = timer;
}
void add(int idx, long long val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}
void range_update(int l, int r, long long val) {
    add(l, val);
    add(r + 1, -val);
}
long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if (!(cin >> n >> q)) return 0;
    for (int i = 1; i <= n; i++) {
        cin >> current_values[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        range_update(in[i], out[i], current_values[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            long long diff = x - current_values[s];
            range_update(in[s], out[s], diff);
            current_values[s] = x;
        } else {
            int s;
            cin >> s;
            cout << query(in[s]) << "\n";
        }
    }
    return 0;
}