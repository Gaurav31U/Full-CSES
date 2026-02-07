#include <bits/stdc++.h>
using namespace std;
long long basis[65];

void insert(long long mask) {
    for (int i = 60; i >= 0; i--) {
        if ((mask >> i) & 1) {
            if (!basis[i]) {
                basis[i] = mask;
                return;
            }
            mask ^= basis[i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (cin >> n >> k) {
        long long val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            insert(val);
        }
        for (int i = 0; i <= 60; i++) {
            if (basis[i]) {
                for (int j = i + 1; j <= 60; j++) {
                    if ((basis[j] >> i) & 1) {
                        basis[j] ^= basis[i];
                    }
                }
            }
        }
        vector<long long> D;
        for (int i = 0; i <= 60; i++) {
            if (basis[i]) {
                D.push_back(basis[i]);
            }
        }
        int rank = D.size();
        long long zeros = n - rank;
        long long multiplier;
        if (zeros >= 60) {
            multiplier = k + 7;
        } else {
            if (zeros >= 20) {
                multiplier = k + 7;
            } else {
                multiplier = (1LL << zeros);
            }
        }

        long long count = 0;  
        long long idx = 0;  

        while (count < k) {
            long long current_val = 0;
            
            for (int t = 0; t < D.size(); t++) {
                if ((idx >> t) & 1) {
                    current_val ^= D[t];
                }
            }

            long long to_print = multiplier;
            if (count + to_print > k) {
                to_print = k - count;
            }

            for (int i = 0; i < to_print; i++) {
                cout << current_val << ((count + i + 1 == k) ? "" : " ");
            }

            count += to_print;
            idx++;
        }
        cout << "\n";
    }

    return 0;
}