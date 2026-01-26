#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    const long long INF = 4000000000000000000LL;
    long long min_sum = INF;
    long long max_sum = -INF;
    long long min_diff = INF;
    long long max_diff = -INF;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        long long sum = x + y;
        long long diff = x - y;

        if (sum < min_sum) min_sum = sum;
        if (sum > max_sum) max_sum = sum;

        if (diff < min_diff) min_diff = diff;
        if (diff > max_diff) max_diff = diff;
        
        long long current_max_dist = max(max_sum - min_sum, max_diff - min_diff);
        cout << current_max_dist << "\n";
    }
    return 0;
}