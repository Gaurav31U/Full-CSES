#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin >> s;
    long long dp = 1;
    vector<long long> last(26, 0);
    for (char c : s) {
        int char_index = c - 'a';
        long long current_dp_state = dp;
        dp = (dp * 2) % MOD;
        if (last[char_index] > 0) {
            dp = (dp - last[char_index] + MOD) % MOD;
        }
        last[char_index] = current_dp_state;
    }
    cout << (dp - 1 + MOD) % MOD << endl;

    return 0;
}