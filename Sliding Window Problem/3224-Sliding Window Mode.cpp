#include <bits/stdc++.h>
using namespace std;
const int MAX_SZ = 262144;
pair<int, int> tree[2 * MAX_SZ]; 
int sz = 1;
void update(int idx, int delta) {
    int p = idx + sz;
    tree[p].first += delta; 
    for (p /= 2; p >= 1; p /= 2) {
        tree[p] = max(tree[2 * p], tree[2 * p + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;cin >> n >> k;

    vector<int> a(n);
    vector<int> coords;
    coords.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        coords.push_back(a[i]);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    int distinct_cnt = coords.size();
    while (sz < distinct_cnt) sz *= 2;

    for (int i = 0; i < sz; i++) {
        if (i < distinct_cnt) {
            tree[sz + i] = {0, -coords[i]};
        } else {
            tree[sz + i] = {-1, -(int)2e9};
        }
    }
    for (int i = sz - 1; i > 0; i--) {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    vector<int> compressed_a(n);
    for(int i = 0; i < n; i++) {
        compressed_a[i] = lower_bound(coords.begin(), coords.end(), a[i]) - coords.begin();
    }
    for (int i = 0; i < k; i++) {
        update(compressed_a[i], 1);
    }
    cout << -tree[1].second; 

    for (int i = k; i < n; i++) {
        update(compressed_a[i - k], -1);
        update(compressed_a[i], 1);
        
        cout << " " << -tree[1].second;
    }
    cout << "\n";

    return 0;
}