#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<int> lngv(n, -1), rngv(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && h[s.top()] <= h[i]) s.pop();
        if (!s.empty()) lngv[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && h[s.top()] <= h[i]) s.pop();
        if (!s.empty()) rngv[i] = s.top();
        s.push(i);
    }
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    sort(order.begin(), order.end(), [&](int a, int b) {
        return h[a] > h[b];
    });
    vector<int> dp(n, 1);
    int result = 0;
    for (int i : order) {
        if (lngv[i] != -1) {
            dp[i] = max(dp[i], dp[lngv[i]] + 1);
        }
        if (rngv[i] != -1) {
            dp[i] = max(dp[i], dp[rngv[i]] + 1);
        }
        result = max(result, dp[i]);
    }
    cout << result << endl;
    return 0;
}