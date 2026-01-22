#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
vector<int> adj[MAXN];
int initial_values[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], sz[MAXN];
int cur_pos = 0; 
int n;
int tree[2 * MAXN];
void update_seg(int p, int value) {
    for (tree[p += n] = value; p > 1; p >>= 1) {
        tree[p >> 1] = max(tree[p], tree[p ^ 1]);
    }
}
int query_seg(int l, int r) {
    int res = 0;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, tree[l++]);
        if (!(r & 1)) res = max(res, tree[r--]);
    }
    return res;
}
void dfs_sz(int u, int p, int d) {
    sz[u] = 1;
    parent[u] = p;
    depth[u] = d;
    heavy[u] = -1;
    int max_sz = 0;
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs_sz(v, u, d + 1);
            sz[u] += sz[v];
            if (sz[v] > max_sz) {
                max_sz = sz[v];
                heavy[u] = v;
            }
        }
    }
}

void dfs_hld(int u, int h) {
    head[u] = h;
    pos[u] = cur_pos++; 
    if (heavy[u] != -1) {
        dfs_hld(heavy[u], h);
    }
    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u]) {
            dfs_hld(v, v);
        }
    }
}
int query_path(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, query_seg(pos[head[a]], pos[a]));
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    res = max(res, query_seg(pos[a], pos[b]));
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if (!(cin >> n >> q)) return 0;
    for (int i = 1; i <= n; i++) cin >> initial_values[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_sz(1, 0, 0);
    dfs_hld(1, 1);
    for (int i = 1; i <= n; i++) {
        update_seg(pos[i], initial_values[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            update_seg(pos[s], x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query_path(a, b) << " ";
        }
    }
    cout << "\n";
    return 0;
}