#include <bits/stdc++.h>
using namespace std;
long long gcd_val(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
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
        long long boundary_points = 0;
        long long double_area = 0;

        for (int i = 0; i < n; ++i) {
            int next_i = (i + 1) % n;
            long long dx = abs(x[next_i] - x[i]);
            long long dy = abs(y[next_i] - y[i]);
            boundary_points += gcd_val(dx, dy);
            double_area += (x[i] * y[next_i]) - (x[next_i] * y[i]);
        }
        double_area = abs(double_area);
        long long inside_points = (double_area - boundary_points + 2) / 2;
        cout << inside_points << " " << boundary_points << endl;
    }
    return 0;
}