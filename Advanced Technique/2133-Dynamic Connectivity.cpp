#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAX_TIMELINE = 100005; 
struct Edge {
    int u, v;
};
int parent_dsu[MAXN];
int sz[MAXN];
int num_components;

struct RollbackInfo {
    int u, v, prev_sz;
    bool joined; 
};
vector<RollbackInfo> history_stack;
vector<Edge> tree[4 * MAX_TIMELINE];

void init_dsu(int n) {
    num_components = n;
    for (int i = 1; i <= n; i++) {
        parent_dsu[i] = i;
        sz[i] = 1;
    }
}
int find_set(int v) {
    if (v == parent_dsu[v]) return v;
    return find_set(parent_dsu[v]);
}
void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (sz[a] > sz[b]) swap(a, b);
        
        parent_dsu[a] = b;
        int old_sz = sz[b];
        sz[b] += sz[a];
        num_components--;
        
        history_stack.push_back({a, b, old_sz, true});
    } else {
        history_stack.push_back({0, 0, 0, false});
    }
}

void rollback() {
    RollbackInfo info = history_stack.back();
    history_stack.pop_back();
    
    if (info.joined) {
        int u = info.u;
        int v = info.v;
        
        parent_dsu[u] = u; 
        sz[v] = info.prev_sz; 
        num_components++;
    }
}
void add_to_tree(int node, int l, int r, int ql, int qr, Edge e) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        tree[node].push_back(e);
        return;
    }
    int mid = l + (r - l) / 2;
    add_to_tree(node * 2, l, mid, ql, qr, e);
    add_to_tree(node * 2 + 1, mid + 1, r, ql, qr, e);
}
void solve(int node, int l, int r, int k_limit) {
    int operations_performed = 0;
    for (const auto& e : tree[node]) {
        unite(e.u, e.v);
        operations_performed++;
    }
    if (l == r) {
        cout << num_components << (l == k_limit ? "" : " ");
    } 
    else {
        int mid = l + (r - l) / 2;
        solve(node * 2, l, mid, k_limit);
        solve(node * 2 + 1, mid + 1, r, k_limit);
    }
    while (operations_performed--) {
        rollback();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    
    init_dsu(n);
    map<pair<int, int>, int> edge_start;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edge_start[{u, v}] = 0;
    }
    
    struct QueryData { int type, u, v; };
    vector<QueryData> queries(k);
    
    for (int i = 0; i < k; i++) {
        cin >> queries[i].type >> queries[i].u >> queries[i].v;
        if (queries[i].u > queries[i].v) swap(queries[i].u, queries[i].v);
    }

    for (int i = 0; i < k; i++) {
        int time_now = i + 1; 
        int u = queries[i].u;
        int v = queries[i].v;
        pair<int, int> edge = {u, v};
        
        if (queries[i].type == 1) {
            edge_start[edge] = time_now;
        } else {
            if (edge_start.count(edge)) {
                int start = edge_start[edge];
                add_to_tree(1, 0, k, start, time_now - 1, {u, v});
                edge_start.erase(edge);
            }
        }
    }
    for (auto const& [key, start] : edge_start) {
        add_to_tree(1, 0, k, start, k, {key.first, key.second});
    }
    solve(1, 0, k, k);
    cout << "\n";
    
    return 0;
}