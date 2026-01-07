#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0};
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                pair<int, int> current = dp[mask];
                pair<int, int> next;
                if (current.second + w[i] <= x) {
                    next = {current.first, current.second + w[i]};
                } 
                else {
                    next = {current.first + 1, w[i]};
                }
                if (next < dp[mask | (1 << i)]) {
                    dp[mask | (1 << i)] = next;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}