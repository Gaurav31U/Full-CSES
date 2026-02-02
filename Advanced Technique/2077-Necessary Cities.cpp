#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
int tin[MAXN];     
int low[MAXN];  
int timer;         
vector<bool> is_ap;
bool visited[MAXN];
void dfs(int u, int p = -1) {
    visited[u] = true; 
    tin[u] = low[u] = ++timer;
    int children = 0; 
    for (int v : adj[u]) {
        if (v == p) {
            continue; 
        }
        if (tin[v] != -1) {
            low[u] = min(low[u], tin[v]);
        } else {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (p != -1 && low[v] >= tin[u]) {
                is_ap[u] = true;
            }
        }
    }
    if (p == -1 && children > 1) {
        is_ap[u] = true;
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
    is_ap.assign(n + 1, false);
    for(int i = 1; i <= n; i++) {
        if(tin[i] == -1) {
            dfs(i, -1);
        }
    }
    vector<int> result_cities;
    for(int i = 1; i <= n; i++) {
        if (is_ap[i]) {
            result_cities.push_back(i);
        }
    }
    cout << result_cities.size() << "\n";
    for (int i = 0; i < result_cities.size(); i++) {
        cout << result_cities[i] << (i == result_cities.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}