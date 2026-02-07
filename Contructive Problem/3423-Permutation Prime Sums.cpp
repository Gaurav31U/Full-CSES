#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int limit = 2 * n;
        vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= limit; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= limit; i += p)
                    is_prime[i] = false;
            }
        }
        vector<int> primes;
        for (int p = 2; p <= limit; p++) {
            if (is_prime[p]) {
                primes.push_back(p);
            }
        }
        vector<int> b(n + 1);
        int current = n;

        while (current > 0) {
            auto it = lower_bound(primes.begin(), primes.end(), current + 1);
            int p = *it;
            int low = p - current;
            for (int i = low; i <= current; ++i) {
                b[i] = p - i;
            }
            current = low - 1;
        }

        for (int i = 1; i <= n; ++i) {
            cout << i << (i == n ? "" : " ");
        }
        cout << "\n";

        for (int i = 1; i <= n; ++i) {
            cout << b[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}