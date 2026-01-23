#include <iostream>
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
int main() {
    ll n;
    if (cin >> n) {
        ll e1 = n * n;
        ll e2 = (e1 + 1) / 2;
        ll e3 = (e1 + 3) / 4;
        ll term1 = power(2, e1);     
        ll term2 = power(2, e2);    
        ll term3 = power(2, e3);  
        ll sum = (term1 + term2 + 2 * term3) % MOD;
        ll ans = (sum * modInverse(4)) % MOD;
        cout << ans << "\n";
    }
    return 0;
}