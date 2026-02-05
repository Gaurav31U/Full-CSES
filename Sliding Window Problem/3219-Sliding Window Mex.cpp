#include <bits/stdc++.h>
using namespace std;
const int MAX_SZ = 262144;
int tree[2 * MAX_SZ];
void update(int val, int delta) {
    if (val >= MAX_SZ) return;
    int idx = val + MAX_SZ;
    tree[idx] += delta;
    for (idx /= 2; idx >= 1; idx /= 2) {
        tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    }
}
int get_mex() {
    int idx = 1; 
    while (idx < MAX_SZ) {
        if (tree[2 * idx] == 0) {
            idx = 2 * idx;
        } else {
            idx = 2 * idx + 1;
        }
    }
    return idx - MAX_SZ;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) 
        cin >> x[i];
    
    for (int i = 0; i < k; i++) 
        update(x[i], 1);
    
    cout << get_mex();

    for (int i = k; i < n; i++) {
        update(x[i - k], -1);
        update(x[i], 1);
        
        cout << " " << get_mex();
    }
    return 0;
}