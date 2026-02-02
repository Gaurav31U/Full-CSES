#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

struct Edge {
    int to;
    int rev;  
    int cap;    
    int cost;   
};
vector<vector<Edge>> adj;
vector<long long> dist; 
vector<long long> h;  
vector<int> p_node;    
vector<int> p_edge;        
void add_edge(int u, int v, int cap, int cost) {
    Edge a = {v, (int)adj[v].size(), cap, cost};
    Edge b = {u, (int)adj[u].size(), 0, -cost};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    adj.assign(n + 1, vector<Edge>());

    for (int i = 0; i < m; ++i) {
        int u, v, r, c;
        cin >> u >> v >> r >> c;
        add_edge(u, v, r, c);
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

            for (int i = 0; i < adj[u].size(); ++i) {
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
        if (dist[t] == INF) break;

        for (int i = 1; i <= n; ++i) {
            if (dist[i] != INF) {
                h[i] += dist[i];
            }
        }

        int push = k - flow_delivered;
        int curr = t;
        while (curr != s) {
            int prev = p_node[curr];
            int idx = p_edge[curr];
            push = min(push, adj[prev][idx].cap);
            curr = prev;
        }

        flow_delivered += push;
        curr = t;
        while (curr != s) {
            int prev = p_node[curr];
            int idx = p_edge[curr];

            adj[prev][idx].cap -= push;
            int rev_idx = adj[prev][idx].rev;
            adj[curr][rev_idx].cap += push;

            total_cost += (long long)push * adj[prev][idx].cost;
            curr = prev;
        }
    }

    if (flow_delivered < k) {
        cout << -1 << endl;
    } else {
        cout << total_cost << endl;
    }

    return 0;
}