#include <bits/stdc++.h>
using namespace std;
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    fast_io();
    int n, k;cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        string s;cin >> s;
        int val = 0;
        for (char c : s) {
            val = (val << 1) | (c - '0');
        }
        nums[i] = val;
    }
    int min_dist = k + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xor_val = nums[i] ^ nums[j];
            int dist = __builtin_popcount(xor_val);
            if (dist < min_dist) {
                min_dist = dist;
                if (min_dist == 0) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    cout << min_dist << endl;
    return 0;
}