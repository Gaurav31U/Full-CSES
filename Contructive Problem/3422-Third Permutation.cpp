#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> c(n);
    vector<int> free_nums(n);
    iota(free_nums.begin(), free_nums.end(), 1);

    for (int i = 0; i < n; ++i) {
        int best_idx = -1;
        int sz = free_nums.size();
        for (int k = 0; k < 3 && k < sz; ++k) {
            int candidate_idx = sz - 1 - k;
            int val = free_nums[candidate_idx];
            if (val != a[i] && val != b[i]) {
                best_idx = candidate_idx;
                break;
            }
        }
        
        if (best_idx != -1) {
            c[i] = free_nums[best_idx];
        
            free_nums[best_idx] = free_nums.back();
            free_nums.pop_back();
        } else {
            c[i] = free_nums.back();
            free_nums.pop_back();
            bool solved = false;
            for (int j = 0; j < i; ++j) {
                if (c[i] != a[j] && c[i] != b[j] &&  
                    c[j] != a[i] && c[j] != b[i]) {  
                    swap(c[i], c[j]);
                    solved = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] == a[i] || c[i] == b[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << c[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}