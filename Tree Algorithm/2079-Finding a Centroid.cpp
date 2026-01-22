#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200005; 
vector<int> adj[MAXN]; 
int sz[MAXN];     
int n;
int centroid = -1;    
void dfs(int u, int p) {
    sz[u] = 1;
    bool is_centroid = true;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u); 
            sz[u] += sz[v];
            if (sz[v] > n / 2) {
                is_centroid = false;
            }
        }
    }
    if (n - sz[u] > n / 2) {
        is_centroid = false;
    }
    if (is_centroid) {
        centroid = u;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (cin >> n) {
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, -1);
        cout << centroid << endl;
    }
    return 0;
}