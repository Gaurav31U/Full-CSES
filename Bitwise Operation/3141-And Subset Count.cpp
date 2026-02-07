#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int NUM_BITS = 18;
const int SIZE = 1 << NUM_BITS;

long long dp[SIZE];
long long pow2[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            dp[a]++;
        }
        for (int i = 0; i < NUM_BITS; i++) {
            for (int mask = 0; mask < SIZE; mask++) {
                if (!(mask & (1 << i))) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            long long cnt = dp[i];
            dp[i] = (pow2[cnt] - 1 + MOD) % MOD;
        }
        for (int i = 0; i < NUM_BITS; i++) {
            for (int mask = 0; mask < SIZE; mask++) {
                if (!(mask & (1 << i))) {
                    dp[mask] = (dp[mask] - dp[mask ^ (1 << i)] + MOD) % MOD;
                }
            }
        }
        for (int k = 0; k <= n; k++) {
            cout << dp[k] << (k == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}