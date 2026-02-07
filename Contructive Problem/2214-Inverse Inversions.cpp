#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k;
    if (cin >> n >> k) {
        vector<int> p(n);
        int low = 1;
        int high = n;

        for (int i = 0; i < n; ++i) {
            long long remaining = n - 1 - i;

            if (k >= remaining) {
                p[i] = high;
                high--;
                k -= remaining;
            } else {
                p[i] = low;
                low++;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] << (i == n - 1 ? "" : " ");
        }
    }
    return 0;
}