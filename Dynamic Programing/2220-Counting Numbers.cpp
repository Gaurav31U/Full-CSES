#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
ll memo[20][12][2][2];
string s;
ll dp(int pos, int last_digit, bool is_tight, bool is_started) {
    if (pos == s.size()) {
        return 1;
    }
    if (memo[pos][last_digit][is_tight][is_started] != -1) {
        return memo[pos][last_digit][is_tight][is_started];
    }
    ll count = 0;
    int limit = is_tight ? (s[pos] - '0') : 9;
    for (int d = 0; d <= limit; d++) {
        bool next_tight = is_tight && (d == limit);
        if (!is_started) {
            if (d == 0) {
                count += dp(pos + 1, 10, next_tight, false);
            } else {
                count += dp(pos + 1, d, next_tight, true);
            }
        } else {
            if (d != last_digit) {
                count += dp(pos + 1, d, next_tight, true);
            }
        }
    }
    return memo[pos][last_digit][is_tight][is_started] = count;
}
ll solve(ll n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return dp(0, 10, true, false);
}
int main() {
    ll a, b;
    if (cin >> a >> b) {
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}