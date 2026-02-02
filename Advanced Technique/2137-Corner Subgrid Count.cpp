#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
const int MAXN = 3000;
bitset<MAXN> grid[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for (int i = 0; i < n; i++) {
        string s;cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                grid[i][j] = 1;
            }
        }
    }
    long long total_subgrids = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int common_cols = (grid[i] & grid[j]).count();
            if (common_cols >= 2) {
                total_subgrids += (long long)common_cols * (common_cols - 1) / 2;
            }
        }
    }
    cout << total_subgrids << endl;
    return 0;
}