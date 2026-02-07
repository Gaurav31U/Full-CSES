#include <bits/stdc++.h>
using namespace std;
const int M = 1 << 20;

void fwht(vector<long long>& a, bool inv) {
    int n = a.size();
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                long long u = a[i + j];
                long long v = a[i + len + j];
                a[i + j] = u + v;
                a[i + len + j] = u - v;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<long long> cnt(M, 0);
        int current_prefix = 0;
        cnt[0]++;
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            current_prefix ^= x;
            cnt[current_prefix]++;
        }
        fwht(cnt, false);
        for (int i = 0; i < M; i++) {
            cnt[i] = cnt[i] * cnt[i];
        }
        fwht(cnt, true);
        vector<int> result;
        if (cnt[0] > (n + 1)) {
            result.push_back(0);
        }
        for (int k = 1; k < M; k++) {
            if (cnt[k] > 0) {
                result.push_back(k);
            }
        }
        cout << result.size() << "\n";
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}