#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int steps = n - k;
        for (int bit = 0; (1 << bit) <= steps; bit++) {
            int jump = 1 << bit;
            
            if (steps & jump) {
                for (int i = 0; i < n - jump; i++) {
                    a[i] = a[i] ^ a[i + jump];
                }
                n -= jump;
            }
        }
        for (int i = 0; i < k; i++) {
            cout << a[i] << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}