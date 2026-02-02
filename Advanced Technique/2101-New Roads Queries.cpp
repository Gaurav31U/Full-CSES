#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAX_NODES = 400005; 
const int LOG = 20; 

int n, m, q;
int dsu_parent[MAX_NODES];
int val[MAX_NODES]; 
vector<int> adj[MAX_NODES];
int up[MAX_NODES][LOG];
int depth[MAX_NODES]; 
int find_set(int v) {
    if (v == dsu_parent[v]) return v;
    return dsu_parent[v] = find_set(dsu_parent[v]);
}
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> q)) return 0;
    for (int i = 1; i < MAX_NODES; i++) {
        dsu_parent[i] = i;
        val[i] = 0; 
    }
    int cur = n; 
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        
        int ru = find_set(u);
        int rv = find_set(v);
        
        if (ru != rv) {
            cur++; 
            val[cur] = i;
            adj[cur].push_back(ru);
            adj[cur].push_back(rv);
        
            dsu_parent[ru] = cur;
            dsu_parent[rv] = cur;
            dsu_parent[cur] = cur;
        }
    }
    queue<int> que;
    for (int i = 1; i <= cur; i++) {
        if (dsu_parent[i] == i) {
            depth[i] = 1;
            up[i][0] = i; 
            for (int k = 1; k < LOG; k++) up[i][k] = i;
            que.push(i);
        }
    }
    
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        
        for (int v : adj[u]) {
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for (int k = 1; k < LOG; k++) {
                up[v][k] = up[up[v][k-1]][k-1];
            }
            que.push(v);
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (find_set(a) != find_set(b)) {
            cout << -1 << "\n";
        } else {
            int lca = get_lca(a, b);
            cout << val[lca] << "\n";
        }
    }

    return 0;
}