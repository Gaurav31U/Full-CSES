#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
const int LOG = 19;
int t[MAXN];
int up[MAXN][LOG];
int in_deg[MAXN], depth[MAXN], root[MAXN], comp[MAXN], pos[MAXN], clen[MAXN];
bool is_cycle[MAXN];
vector<int> rev[MAXN];

int jump(int a, int k) {
    for (int i = 0; i < LOG; i++) {
        if ((k >> i) & 1) a = up[a][i];
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        up[i][0] = t[i];
        in_deg[t[i]]++;
        rev[t[i]].push_back(i);
    }

    // Binary Lifting Precomputation
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }

    // Kahn's algorithm to identify tree nodes (non-cycle)
    queue<int> qu;
    for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0) qu.push(i);
    }
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        int v = t[u];
        if (--in_deg[v] == 0) qu.push(v);
    }

    // Nodes with in_degree > 0 belong to a cycle
    for (int i = 1; i <= n; i++) if (in_deg[i] > 0) is_cycle[i] = true;

    int current_comp = 0;
    for (int i = 1; i <= n; i++) {
        if (is_cycle[i] && comp[i] == 0) {
            current_comp++;
            vector<int> cycle_nodes;
            int curr = i;
            while (comp[curr] == 0) {
                comp[curr] = current_comp;
                cycle_nodes.push_back(curr);
                curr = t[curr];
            }
            
            int L = cycle_nodes.size();
            for (int j = 0; j < L; j++) {
                int node = cycle_nodes[j];
                pos[node] = j;
                clen[node] = L;
                root[node] = node;
                depth[node] = 0;
            }

            // Propagate data to trees feeding into these cycle nodes
            for (int node : cycle_nodes) {
                vector<int> st = {node};
                while (!st.empty()) {
                    int u = st.back(); st.pop_back();
                    for (int v : rev[u]) {
                        if (!is_cycle[v]) {
                            comp[v] = current_comp;
                            root[v] = node;
                            depth[v] = depth[u] + 1;
                            st.push_back(v);
                        }
                    }
                }
            }
        }
    }

    // Handle queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (comp[a] != comp[b]) {
            cout << "-1\n"; continue;
        }

        if (!is_cycle[b]) { // b is in a tree branch
            if (depth[a] >= depth[b] && jump(a, depth[a] - depth[b]) == b)
                cout << depth[a] - depth[b] << "\n";
            else
                cout << "-1\n";
        } else { // b is on the cycle
            int d_to_cycle = depth[a];
            int a_cyc = root[a];
            int d_on_cycle = (pos[b] - pos[a_cyc] + clen[b]) % clen[b];
            cout << d_to_cycle + d_on_cycle << "\n";
        }
    }

    return 0;
}