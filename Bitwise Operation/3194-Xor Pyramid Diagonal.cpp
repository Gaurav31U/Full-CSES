#include <bits/stdc++.h>
using namespace std;
const int MAX_BITS = 18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int size = 1 << MAX_BITS;
        vector<int> dp(size, 0);
        
        for (int i = 0; i < n; i++) {
            cin >> dp[i];
        }

        for (int i = 0; i < MAX_BITS; i++) {
            for (int mask = 0; mask < size; mask++) {
                if (mask & (1 << i)) {
                    dp[mask] ^= dp[mask ^ (1 << i)];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << dp[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}