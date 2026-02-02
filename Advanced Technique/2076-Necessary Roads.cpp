#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
int tin[MAXN];    
int low[MAXN];    
int timer;       
vector<pair<int, int>> bridges; 
void dfs(int u, int p = -1) {
    tin[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (tin[v] != -1) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                bridges.push_back({u, v});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    timer = 0;
    fill(tin, tin + n + 1, -1);
    fill(low, low + n + 1, -1);
    dfs(1, -1);
    cout << bridges.size() << "\n";
    for (auto edge : bridges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}