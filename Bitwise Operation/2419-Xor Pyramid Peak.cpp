#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int pascal_row = n - 1;
        int ans = 0;
        int val;

        for (int i = 0; i < n; i++) {
            cin >> val;
            if ((pascal_row & i) == i) {
                ans ^= val;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}