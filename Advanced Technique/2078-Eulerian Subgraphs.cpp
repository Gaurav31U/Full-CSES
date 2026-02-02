#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1e9 + 7;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (cin >> n >> m) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        vector<bool> visited(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }
        long long exponent = m - n + components;
        cout << power(2, exponent) << endl;
    }
    return 0;
}