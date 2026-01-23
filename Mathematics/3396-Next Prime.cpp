#include <iostream>
using namespace std;
typedef long long ll;
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
void solve() {
    ll n;cin >> n;
    ll candidate = n + 1;
    while (true) {
        if (isPrime(candidate)) {
            cout << candidate << "\n";
            return;
        }
        candidate++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}