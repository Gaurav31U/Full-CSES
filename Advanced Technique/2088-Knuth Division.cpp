#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MAXN = 5005;
long long dp[MAXN][MAXN];
int opt[MAXN][MAXN];
long long prefix_sum[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        prefix_sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            prefix_sum[i] = prefix_sum[i-1] + x;
            dp[i][i] = 0;
            opt[i][i] = i; 
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                long long current_interval_cost = prefix_sum[j] - prefix_sum[i-1];
                int start_k = opt[i][j-1];
                int end_k = min(opt[i+1][j], j - 1); 
                for (int k = start_k; k <= end_k; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] + current_interval_cost;
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        opt[i][j] = k;
                    }
                }
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}