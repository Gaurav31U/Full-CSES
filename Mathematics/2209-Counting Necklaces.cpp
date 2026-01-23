#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n) {
    return power(n, MOD - 2);
}
ll getPhi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main() {
    int n, m;
    if (cin >> n >> m) {
        ll sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ll d1 = i;
                ll term1 = (getPhi(n / d1) * power(m, d1)) % MOD;
                sum = (sum + term1) % MOD;
                if (i * i != n) {
                    ll d2 = n / i;
                    ll term2 = (getPhi(n / d2) * power(m, d2)) % MOD;
                    sum = (sum + term2) % MOD;
                }
            }
        }
        ll ans = (sum * modInverse(n)) % MOD;
        cout << ans << "\n";
    }
    return 0;
}