#include <bits/stdc++.h>
using namespace std;

const int MAX_BITS = 20;
const int MAX_VAL = 1 << MAX_BITS;

int freq[MAX_VAL];
int dp_subset[MAX_VAL];
int dp_superset[MAX_VAL];
int input_arr[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> input_arr[i];
            freq[input_arr[i]]++;
        }
        for (int i = 0; i < MAX_VAL; i++) {
            dp_subset[i] = freq[i];
            dp_superset[i] = freq[i];
        }
        for (int i = 0; i < MAX_BITS; i++) {
            for (int mask = 0; mask < MAX_VAL; mask++) {
                if (mask & (1 << i)) {
                    dp_subset[mask] += dp_subset[mask ^ (1 << i)];
                }
            }
        }
        for (int i = 0; i < MAX_BITS; i++) {
            for (int mask = 0; mask < MAX_VAL; mask++) {
                if (!(mask & (1 << i))) {
                    dp_superset[mask] += dp_superset[mask | (1 << i)];
                }
            }
        }
        int all_ones = MAX_VAL - 1;
        for (int i = 0; i < n; i++) {
            int x = input_arr[i];

            int count_sub = dp_subset[x];

            int count_super = dp_superset[x];

            int complement = all_ones ^ x;
            int count_disjoint = dp_subset[complement];
            int count_intersect = n - count_disjoint;

            cout << count_sub << " " << count_super << " " << count_intersect << "\n";
        }
    }

    return 0;
}