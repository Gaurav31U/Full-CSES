#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;cin >> n >> k;
    if ((long long)k * k < n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    int current = 1;
    int base_size = n / k;
    int remainder = n % k;

    for (int i = 0; i < k; ++i) {
        int size = base_size + (i < remainder ? 1 : 0);
        int end_val = current + size - 1;
        for (int v = end_val; v >= current; --v) {
            cout << v << " ";
        }
        current += size;
    }
    cout << "\n";
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