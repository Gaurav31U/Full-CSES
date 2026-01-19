#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXM = 200005; // 2 * 10^5 for m and its negation

vector<int> adj[MAXM], rev_adj[MAXM];
vector<int> order;
bool visited[MAXM];
int component[MAXM];
int counter = 0;
int get_neg(int x, int m) {
    return (x <= m) ? x + m : x - m;
}

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int c) {
    component[u] = c;
    for (int v : rev_adj[u]) {
        if (component[v] == -1) dfs2(v, c);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        char s1, s2;
        int x1, x2;
        cin >> s1 >> x1 >> s2 >> x2;
        int u = (s1 == '+') ? x1 : x1 + m;
        int v = (s2 == '+') ? x2 : x2 + m;
        
        int nu = get_neg(u, m);
        int nv = get_neg(v, m);

        adj[nu].push_back(v);
        adj[nv].push_back(u);
        rev_adj[v].push_back(nu);
        rev_adj[u].push_back(nv);
    }

    for (int i = 1; i <= 2 * m; i++) {
        if (!visited[i]) dfs1(i);
    }
    reverse(order.begin(), order.end());
    fill(component, component + 2 * m + 1, -1);
    for (int x : order) {
        if (component[x] == -1) {
            dfs2(x, counter++);
        }
    }
    string res = "";
    for (int i = 1; i <= m; i++) {
        if (component[i] == component[i + m]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        if (component[i] > component[i + m]) {
            res += "+ ";
        } else {
            res += "- ";
        }
    }

    cout << res << endl;
    return 0;
}