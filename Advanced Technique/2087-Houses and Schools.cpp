#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int n, k;
vector<long long> c;
vector<long long> P; 
vector<long long> T;
long long cost_matrix[3005][3005];
long long dp_prev[3005];
long long dp_curr[3005];
long long get_cost_val(int l, int r, int m) {
    long long w_left =    P[m] - P[l-1];
    long long w_right =   P[r] - P[m];
    long long wi_left =   T[m] - T[l-1];
    long long wi_right =  T[r] - T[m];
    return (m * w_left - wi_left) + (wi_right - m * w_right);
}
void precompute_costs() {
    for (int l = 1; l <= n; ++l) {
        int m = l;
        for (int r = l; r <= n; ++r) {
            long long total_weight = P[r] - P[l-1];
            while (m < r && (P[m] - P[l-1]) * 2 < total_weight) {
                m++;
            }
            cost_matrix[l][r] = get_cost_val(l, r, m);
        }
    }
}
void compute_dp(int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) / 2;
    pair<long long, int> best = {INF, -1};
    int search_limit = min(mid - 1, optr);

    for (int p = optl; p <= search_limit; ++p) {
        long long current_val = dp_prev[p] + cost_matrix[p+1][mid];
        if (current_val < best.first) {
            best = {current_val, p};
        }
    }
    dp_curr[mid] = best.first;
    int opt_p = best.second;
    if (opt_p == -1) opt_p = optl;  
    compute_dp(l, mid - 1, optl, opt_p);
    compute_dp(mid + 1, r, opt_p, optr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (cin >> n >> k) {
        c.resize(n + 1);
        P.resize(n + 1, 0);
        T.resize(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
            P[i] = P[i-1] + c[i];
            T[i] = T[i-1] + c[i] * i;
        }
        precompute_costs();
        for (int i = 0; i <= n; ++i) dp_prev[i] = INF;
        dp_prev[0] = 0;
        for (int j = 1; j <= k; ++j) {
            compute_dp(1, n, 0, n - 1);
            for (int i = 0; i <= n; ++i) {
                dp_prev[i] = dp_curr[i];
            }
        }
        cout << dp_prev[n] << endl;
    }
    return 0;
}