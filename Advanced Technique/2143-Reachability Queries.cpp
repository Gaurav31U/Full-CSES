#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;
vector<int> adj[MAXN];     
vector<int> dag_adj[MAXN];    

int tin[MAXN], low[MAXN];     
int timer;         
stack<int> st;              
bool onStack[MAXN];          
int scc_id[MAXN];      
int scc_cnt;           

bitset<MAXN> reach[MAXN];

void dfs(int u) {
    tin[u] = low[u] = ++timer;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (tin[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (low[u] == tin[u]) {
        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;
            scc_id[v] = scc_cnt;
            if (u == v) break;
        }
        scc_cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    if (cin >> n >> m >> q) {
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        fill(tin, tin + n + 1, -1);
        timer = 0;
        scc_cnt = 0;

        for (int i = 1; i <= n; ++i) {
            if (tin[i] == -1) {
                dfs(i);
            }
        }
        for (int u = 1; u <= n; ++u) {
            for (int v : adj[u]) {
                if (scc_id[u] != scc_id[v]) {
                    dag_adj[scc_id[u]].push_back(scc_id[v]);
                }
            }
        }

        for (int i = 0; i < scc_cnt; ++i) {
            sort(dag_adj[i].begin(), dag_adj[i].end());
            dag_adj[i].erase(unique(dag_adj[i].begin(), dag_adj[i].end()), dag_adj[i].end());
        }
        
        for (int i = 0; i < scc_cnt; ++i) {
            reach[i].set(i); 
            for (int neighbor : dag_adj[i]) {
                reach[i] |= reach[neighbor];
            }
        }
        for (int k = 0; k < q; ++k) {
            int a, b;
            cin >> a >> b;
            if (reach[scc_id[a]][scc_id[b]]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}