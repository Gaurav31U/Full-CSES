#include <bits/stdc++.h>
using namespace std;
const int MAX_BITS = 30;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin >> n;
    int basis[MAX_BITS] = {0};

    for (int i = 0; i < n; ++i) {
        int x;cin >> x;
        for (int k = MAX_BITS - 1; k >= 0; --k) {
            if ((x >> k) & 1) {
                if (!basis[k]) {
                    basis[k] = x;
                    break;
                }
                x ^= basis[k];
            }
        }
    }

    int max_xor = 0;
    for (int k = MAX_BITS - 1; k >= 0; --k) {
        if (!basis[k]) continue;
        if ((max_xor ^ basis[k]) > max_xor) {
            max_xor ^= basis[k];
        }
    }
    cout << max_xor << endl;
    return 0;
}