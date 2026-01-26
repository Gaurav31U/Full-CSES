#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<long long> x(n);
        vector<long long> y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        long long double_area = 0;
        for (int i = 0; i < n; ++i) {
            int next_i = (i + 1) % n;
            double_area += (x[i] * y[next_i]) - (x[next_i] * y[i]);
        }
        if (double_area < 0) {
            double_area = -double_area;
        }
        cout << double_area << endl;
    }
    return 0;
}