#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
struct Edge {
    int to;
    int rev;           
    int cap;           
    int cost;           
    int original_id;  
};

int n, m, k;
vector<vector<Edge>> adj;
vector<long long> dist;  
vector<long long> h;    
vector<int> p_node; 
vector<int> p_edge;    
void add_edge(int u, int v, int cost) {
    Edge forward = {v, (int)adj[v].size(), 1, cost, 1};
    Edge backward = {u, (int)adj[u].size(), 0, -cost, -1};
    adj[u].push_back(forward);
    adj[v].push_back(backward);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> k)) return 0;

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1); 
    }

    int s = 1;
    int t = n;
    
    h.assign(n + 1, 0);
    
    long long total_cost = 0;
    int flow_delivered = 0;

    while (flow_delivered < k) {
        dist.assign(n + 1, INF);
        p_node.assign(n + 1, -1);
        p_edge.assign(n + 1, -1);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (int i = 0; i < adj[u].size(); i++) {
                Edge &e = adj[u][i];
                if (e.cap > 0) {
                    long long reduced_cost = e.cost + h[u] - h[e.to];
                    if (dist[u] + reduced_cost < dist[e.to]) {
                        dist[e.to] = dist[u] + reduced_cost;
                        p_node[e.to] = u;
                        p_edge[e.to] = i;
                        pq.push({dist[e.to], e.to});
                    }
                }
            }
        }

        if (dist[t] == INF) {
            cout << -1 << "\n";
            return 0;
        }

        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                h[i] += dist[i];
            }
        }

        int push = 1; 
        flow_delivered += push;
        
        int curr = t;
        while (curr != s) {
            int prev = p_node[curr];
            int idx = p_edge[curr];
            
            adj[prev][idx].cap -= push;
            int rev_idx = adj[prev][idx].rev;
            adj[curr][rev_idx].cap += push;
            
            total_cost += adj[prev][idx].cost;
            curr = prev;
        }
    }

    cout << total_cost << "\n";

    vector<vector<int>> used_edges(n + 1);
    for (int u = 1; u <= n; u++) {
        for (const auto& e : adj[u]) {
            if (e.original_id == 1 && e.cap == 0) {
                used_edges[u].push_back(e.to);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        vector<int> path;
        int curr = s;
        path.push_back(curr);
        
        while (curr != t) {
            int next = used_edges[curr].back();
            used_edges[curr].pop_back(); 
            path.push_back(next);
            curr = next;
        }
        cout << path.size() << "\n";
        for (int j = 0; j < path.size(); j++) {
            cout << path[j] << (j == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}