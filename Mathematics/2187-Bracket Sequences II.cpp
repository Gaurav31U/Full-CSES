#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1000005;
long long fact[MAXN];
long long invFact[MAXN];
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
long long modInverse(long long n) {
    return power(n, MOD - 2);
}
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;
    if (n % 2 != 0) {
        cout << 0 << "\n";
        return;
    }
    int current_bal = 0;
    int current_open = 0;
    for (char c : s) {
        if (c == '(') {
            current_bal++;
            current_open++;
        } else {
            current_bal--;
        }
        if (current_bal < 0) {
            cout << 0 << "\n";
            return;
        }
    }
    if (current_open > n / 2) {
        cout << 0 << "\n";
        return;
    }
    int m = n - s.length();
    int k = n / 2 - current_open;
    long long ans = (nCr(m, k) - nCr(m, k - 1) + MOD) % MOD;
    cout << ans << "\n";
}
int main() {
    precompute();
    solve();
    return 0;
}