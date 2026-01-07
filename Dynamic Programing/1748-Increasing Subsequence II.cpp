#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
struct FenwickTree {
    int n;
    vector<long long> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, long long val) {
        for (; i <= n; i += i & -i) {
            tree[i] = (tree[i] + val) % MOD;
        }
    }
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum = (sum + tree[i]) % MOD;
        }
        return sum;
    }
};
int main() {
    int n;cin >> n;
    vector<int> x(n);
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        coords.push_back(x[i]);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    auto get_rank = [&](int val) {
        return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
    };
    FenwickTree ft(coords.size());
    long long total_count = 0;
    for (int i = 0; i < n; i++) {
        int r = get_rank(x[i]);
        long long sequences_ending_here = (ft.query(r - 1) + 1) % MOD;
        ft.update(r, sequences_ending_here);
        total_count = (total_count + sequences_ending_here) % MOD;
    }
    cout << total_count << endl;
    return 0;
}