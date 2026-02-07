#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin >> n;
    priority_queue<pair<int, int>> pq;
    long long sum_degrees = 0;

    for (int i = 1; i <= n; ++i) {
        int games;
        cin >> games;
        if (games > 0) {
            pq.push({games, i});
            sum_degrees += games;
        }
    }
    if (sum_degrees % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<pair<int, int>> edges;
    edges.reserve(sum_degrees / 2);

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        
        int d = current.first;     
        int u = current.second;   
        
        if (pq.size() < d) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        vector<pair<int, int>> next_candidates;
        for (int i = 0; i < d; ++i) {
            pair<int, int> v_entry = pq.top();
            pq.pop();
            
            int v_deg = v_entry.first;
            int v = v_entry.second;
            
            edges.push_back({u, v});
            
            v_deg--;
            
            if (v_deg > 0) {
                next_candidates.push_back({v_deg, v});
            }
        }
        
        for (const auto& candidate : next_candidates) {
            pq.push(candidate);
        }
    }
    cout << edges.size() << "\n";
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}