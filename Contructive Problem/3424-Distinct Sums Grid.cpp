#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int MAX_SUM = 2000005;

int grid[MAXN][MAXN];
long long r_sum[MAXN];
long long c_sum[MAXN];
int counts[MAX_SUM];
int dist_cnt = 0;
int n;

inline void inc(long long s) {
    if (counts[s] == 0) dist_cnt++;
    counts[s]++;
}

inline void dec(long long s) {
    counts[s]--;
    if (counts[s] == 0) dist_cnt--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n == 1 || n == 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> vals;
    vals.reserve(n * n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            vals.push_back(i);
        }
    }
    srand(time(NULL));
    for (int i = vals.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(vals[i], vals[j]);
    }
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = vals[idx++];
            r_sum[i] += grid[i][j];
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            c_sum[j] += grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) inc(r_sum[i]);
    for (int j = 0; j < n; ++j) inc(c_sum[j]);

    int max_ops = 5000000; 
    
    while (dist_cnt < 2 * n && max_ops > 0) {
        max_ops--;
        int r1 = rand() % n;
        int c1 = rand() % n;
        int r2 = rand() % n;
        int c2 = rand() % n;

        if ((r1 == r2 && c1 == c2) || grid[r1][c1] == grid[r2][c2]) continue;

        int v1 = grid[r1][c1];
        int v2 = grid[r2][c2];

        long long or1 = r_sum[r1];
        long long oc1 = c_sum[c1];
        long long or2 = r_sum[r2];
        long long oc2 = c_sum[c2];

        dec(or1);
        if (r1 != r2) dec(or2);
        dec(oc1);
        if (c1 != c2) dec(oc2);

        long long nr1 = or1 - v1 + v2;
        long long nc1 = oc1 - v1 + v2;
        long long nr2 = or2 - v2 + v1;
        long long nc2 = oc2 - v2 + v1;
        
        if (r1 == r2) { nr1 = or1; nr2 = or2; }
        if (c1 == c2) { nc1 = oc1; nc2 = oc2; }

        inc(nr1);
        if (r1 != r2) inc(nr2);
        inc(nc1);
        if (c1 != c2) inc(nc2);

        
        int new_dist = dist_cnt;
        dec(nr1); if (r1 != r2) dec(nr2); dec(nc1); if (c1 != c2) dec(nc2);
        inc(or1); if (r1 != r2) inc(or2); inc(oc1); if (c1 != c2) inc(oc2);
        
        int current_score = 0;
        int new_score = 0;
        int saved_dist = dist_cnt;
        
        dec(or1); if (r1!=r2) dec(or2); dec(oc1); if (c1!=c2) dec(oc2);
        inc(nr1); if (r1!=r2) inc(nr2); inc(nc1); if (c1!=c2) inc(nc2);
        
        if (dist_cnt >= saved_dist) {
            grid[r1][c1] = v2;
            grid[r2][c2] = v1;
            r_sum[r1] = nr1; c_sum[c1] = nc1;
            r_sum[r2] = nr2; c_sum[c2] = nc2;
        } else {
            dec(nr1); if (r1!=r2) dec(nr2); dec(nc1); if (c1!=c2) dec(nc2);
            inc(or1); if (r1!=r2) inc(or2); inc(oc1); if (c1!=c2) inc(oc2);
        }
    }

    if (dist_cnt < 2*n) {
        cout << "IMPOSSIBLE\n"; 
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}