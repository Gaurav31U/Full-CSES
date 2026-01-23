#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MOD = 1e9 + 7;
int spf[MAXN];
int max_pow[MAXN];
void sieve() {
    for (int i = 0; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}
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
void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int curr = i;
            int len = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = p[curr];
                len++;
            }
            int temp = len;
            while (temp > 1) {
                int prime = spf[temp];
                int count = 0;
                while (temp % prime == 0) {
                    temp /= prime;
                    count++;
                }
                max_pow[prime] = max(max_pow[prime], count);
            }
        }
    }
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        if (max_pow[i] > 0) {
            ans = (ans * power(i, max_pow[i])) % MOD;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    solve();
    return 0;
}