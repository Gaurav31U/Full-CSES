#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
vector<int> adj[MAXN];
int sz[MAXN];
bool removed[MAXN];
ll bit[MAXN];
int cur_limit;

// Fenwick Tree: update and query operations
void update(int i, ll val) {
    for (i++; i <= cur_limit; i += i & -i) bit[i] += val;
}

ll query(int i) {
    if (i < 0) return 0;
    i = min(i, cur_limit - 1);
    ll res = 0;
    for (i++; i > 0; i -= i & -i) res += bit[i];
    return res;
}

// Calculate subtree sizes for centroid finding
void get_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            get_sz(v, u);
            sz[u] += sz[v];
        }
    }
}

// Find the centroid of the current tree/component
int get_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v != p && !removed[v] && sz[v] > total / 2) {
            return get_centroid(v, u, total);
        }
    }
    return u;
}

// Collect all node distances from the current centroid
vector<int> current_dists;
void get_dists(int u, int p, int d, int k2) {
    if (d > k2) return; // Optimization: distances > k2 cannot form valid paths
    current_dists.push_back(d);
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            get_dists(v, u, d + 1, k2);
        }
    }
}

ll total_paths = 0;
int k1, k2;

void solve(int u) {
    get_sz(u, -1);
    int total_nodes = sz[u];
    int c = get_centroid(u, -1, total_nodes);
    removed[c] = true;

    // Use current component size or k2 to bound BIT size
    cur_limit = min(total_nodes, k2 + 1);
    
    // Distance 0 represents the centroid itself
    update(0, 1);
    vector<int> all_dists;

    for (int v : adj[c]) {
        if (!removed[v]) {
            current_dists.clear();
            get_dists(v, c, 1, k2);
            for (int d : current_dists) {
                // Find nodes in previous subtrees with distance d' such that k1 <= d + d' <= k2
                total_paths += query(k2 - d) - query(k1 - d - 1);
            }
            for (int d : current_dists) {
                update(d, 1);
                all_dists.push_back(d);
            }
        }
    }

    // Reset BIT for the next centroid at the same or different level
    update(0, -1);
    for (int d : all_dists) update(d, -1);

    // Recurse into subtrees
    for (int v : adj[c]) {
        if (!removed[v]) solve(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n >> k1 >> k2)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    current_dists.reserve(n);
    solve(1);
    cout << total_paths << endl;

    return 0;
}