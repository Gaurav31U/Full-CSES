#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
vector<int> adj[MAXN];  
bool removed[MAXN];    
int sz[MAXN];  
int cnt[MAXN];  
int n, k;
long long ans = 0; 
void calc_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            calc_sz(v, u);
            sz[u] += sz[v];
        }
    }
}
int find_centroid(int u, int p, int tree_size) {
    for (int v : adj[u]) {
        if (v != p && !removed[v] && sz[v] > tree_size / 2) {
            return find_centroid(v, u, tree_size);
        }
    }
    return u;
}
void get_dists(int u, int p, int d, vector<int>& dists) {
    if (d > k) return; 
    dists.push_back(d);
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            get_dists(v, u, d + 1, dists);
        }
    }
}
void decompose(int u) {
    calc_sz(u, -1);
    int c = find_centroid(u, -1, sz[u]);
    removed[c] = true;
    cnt[0] = 1; 
    vector<int> nodes_to_clear; 
    for (int v : adj[c]) {
        if (!removed[v]) {
            vector<int> component_dists;
            get_dists(v, c, 1, component_dists);
            for (int d : component_dists) {
                if (k - d >= 0) {
                    ans += cnt[k - d];
                }
            }
            for (int d : component_dists) {
                if (d <= k) {
                    cnt[d]++;
                    nodes_to_clear.push_back(d);
                }
            }
        }
    }
    for (int d : nodes_to_clear) {
        cnt[d]--;
    }
    cnt[0] = 0; 
    for (int v : adj[c]) {
        if (!removed[v]) {
            decompose(v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (cin >> n >> k) {
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        decompose(1);
        cout << ans << endl;
    }
    return 0;
}