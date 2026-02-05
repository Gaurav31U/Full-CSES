#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    int agg;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;cin >>n>>k;

    long long x_param, a, b, c;
    cin >> x_param >> a >> b >> c;

    vector<Node> s1, s2;
    s1.reserve(k);
    s2.reserve(k);

    long long cur = x_param;
    long long total_xor = 0;

    for (int i = 0; i < n; ++i) {
        int val = (int)cur;

        cur = (a * cur + b) % c;

        int current_s1_agg = s1.empty() ? val : (s1.back().agg | val);
        s1.push_back({val, current_s1_agg});

        if (i >= k - 1) {
            int s1_agg = s1.empty() ? 0 : s1.back().agg;
            int s2_agg = s2.empty() ? 0 : s2.back().agg;
            int window_or = s1_agg | s2_agg;
            
            total_xor ^= window_or;

            if (s2.empty()) {
                while (!s1.empty()) {
                    int v = s1.back().val;
                    s1.pop_back();
                    int new_agg = s2.empty() ? v : (s2.back().agg | v);
                    s2.push_back({v, new_agg});
                }
            }
            s2.pop_back();
        }
    }

    cout << total_xor << endl;

    return 0;
}