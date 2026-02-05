#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
int bit[MAXN];
int max_val;
void update(int idx, int val) {
    for (; idx <= max_val; idx += idx & -idx) {
        bit[idx] += val;
    }
}
int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
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
    max_val = coords.size();

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(coords.begin(), coords.end(), a[i]) - coords.begin() + 1;
    }

    ll current_inversions = 0;

    for (int i = 0; i < k; i++) {
        current_inversions += (i - query(a[i]));
        update(a[i], 1);
    }

    cout << current_inversions;

    for (int i = k; i < n; i++) {
        int out_val = a[i - k];
        current_inversions -= query(out_val - 1);
        update(out_val, -1);
        int in_val = a[i];
        current_inversions += (k - 1) - query(in_val);
        update(in_val, 1);

        cout << " " << current_inversions;
    }
    cout << "\n";

    return 0;
}