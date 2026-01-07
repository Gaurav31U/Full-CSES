#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> x(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        total_sum += x[i];
    }
    vector<long long> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = x[i];
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i] = max(x[i] - dp[i + 1], x[j] - dp[i]);
        }
    }
    long long relative_diff = dp[0];
    long long player1_score = (total_sum + relative_diff) / 2;
    cout << player1_score << endl;
    return 0;
}