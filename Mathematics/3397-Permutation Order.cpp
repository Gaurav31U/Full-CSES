#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[21];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = fact[i - 1] * i;
    }
}
void solve() {
    int type;cin >> type;
    int n;cin >> n;
    vector<int> available;
    for (int i = 1; i <= n; i++) {
        available.push_back(i);
    } 
    if (type == 1) {
        ll k;cin >> k;k--;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            ll blockSize = fact[n - 1 - i];
            int idx = k / blockSize;
            result.push_back(available[idx]);
            available.erase(available.begin() + idx);
            k %= blockSize;
        }
        for (int i = 0; i < n; i++) {
            cout << result[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        vector<int> p(n);
        for (int i=0;i<n;i++) 
            cin >> p[i];
        ll rank = 0;
        for (int i = 0; i < n; i++) {
            ll blockSize = fact[n - 1 - i];
            int idx = 0;
            while (available[idx] != p[i]) {
                idx++;
            }
            rank += idx * blockSize;
            available.erase(available.begin() + idx);
        }
        cout << rank + 1 << "\n"; 
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}