#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
const int MAXN = 50005;
vector<int> adj[MAXN];
bitset<MAXN> reachable[MAXN];
bool visited[MAXN];
vector<int> processing_order;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    processing_order.push_back(u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int u : processing_order) {
        reachable[u][u] = 1; 
        for (int v : adj[u]) {
            reachable[u] |= reachable[v];
        }
    }
    for (int i = 1; i <= n; i++) 
        cout << reachable[i].count() << " ";
    return 0;
}