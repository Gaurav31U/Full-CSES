#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
vector<int> adj[MAXN];
int original_color[MAXN]; 
int flat_color[MAXN];    
int in[MAXN], out[MAXN];
int timer = 0;
vector<pair<int, int>> queries[MAXN];
int ans[MAXN];
map<int, int> last_pos; 
int bit[MAXN];
int n;
void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}
int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}
void dfs(int u, int p) {
    timer++;
    in[u] = timer;
    flat_color[timer] = original_color[u]; 
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    out[u] = timer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) {
        cin >> original_color[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        queries[out[i]].push_back({in[i], i});
    }
    for (int i = 1; i <= n; i++) {
        int color = flat_color[i];
        if (last_pos.count(color)) {
            update(last_pos[color], -1);
        }
        update(i, 1);
        last_pos[color] = i;
        for (auto &q : queries[i]) {
            int L = q.first;
            int node_id = q.second;
            ans[node_id] = query(i) - query(L - 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}