#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int bit[N], res[N], x[N];
int n, q;
void update(int i, int val, int limit) {
    for (; i <= limit; i += i & -i) bit[i] += val;
}
int query(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}
struct Query {
    int idx, c, d, id, sign;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    vector<int> coords;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        coords.push_back(x[i]);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    auto get_v = [&](int val) {
        return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
    };
    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int cl = lower_bound(coords.begin(), coords.end(), c) - coords.begin() + 1;
        int cr = upper_bound(coords.begin(), coords.end(), d) - coords.begin();
        
        if (cl > cr) continue; // No values in range

        // Split query into two parts: [1, b] and [1, a-1]
        queries.push_back({b, cl, cr, i, 1});
        queries.push_back({a - 1, cl, cr, i, -1});
    }

    // Sort all split queries by their index (Sweep-line position)
    sort(queries.begin(), queries.end(), [](Query A, Query B) {
        return A.idx < B.idx;
    });

    int cur_idx = 0;
    int limit = coords.size();
    for (auto &qu : queries) {
        // Add elements to BIT until we reach the index of the query
        while (cur_idx < qu.idx) {
            cur_idx++;
            update(get_v(x[cur_idx]), 1, limit);
        }
        // Result is (Count in range [1, d] - Count in range [1, c-1])
        int count = query(qu.d) - query(qu.c - 1);
        res[qu.id] += qu.sign * count;
    }

    for (int i = 0; i < q; i++) cout << res[i] << "\n";

    return 0;
}