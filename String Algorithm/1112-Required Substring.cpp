#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
int main() {
    int n;
    if (!(cin >> n)) return 0;
    string p;
    cin >> p;
    int m = p.length();
    vector<int> pi(m);
    for (int i = 1; i < m; i++) {
        int j = pi[i-1];
        while (j > 0 && p[i] != p[j])
            j = pi[j-1];
        if (p[i] == p[j])
            j++;
        pi[i] = j;
    }

    vector<vector<int>> trans(m, vector<int>(26));
    for (int j = 0; j < m; j++) {
        for (int c = 0; c < 26; c++) {
            char ch = 'A' + c;
            int k = j;
            while (k > 0 && p[k] != ch)
                k = pi[k-1];
            if (p[k] == ch)
                k++;
            trans[j][c] = k;
        }
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(m, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == 0) continue;
            
            for (int c = 0; c < 26; c++) {
                int next_state = trans[j][c];
                if (next_state < m) {
                    dp[i+1][next_state] = (dp[i+1][next_state] + dp[i][j]) % MOD;
                }
            }
        }
    }
    long long count_without = 0;
    for (int j = 0; j < m; j++) {
        count_without = (count_without + dp[n][j]) % MOD;
    }

    long long total = power(26, n);
    long long ans = (total - count_without + MOD) % MOD;

    cout << ans << endl;

    return 0;
}