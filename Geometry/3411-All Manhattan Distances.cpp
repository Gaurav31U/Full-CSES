#include <bits/stdc++.h>
using namespace std;
void print128(__int128_t n) {
    if (n == 0) {
        cout << "0\n";
        return;
    }
    if (n < 0) {
        cout << '-';
        n = -n;
    }

    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

__int128_t calc_dimension_sum(vector<long long>& coords) {
    sort(coords.begin(), coords.end());
    
    __int128_t total_diff = 0;
    long long n = coords.size();
    
    for (long long i = 0; i < n; ++i) {
        
        long long count_smaller = i;
        long long count_larger = n - 1 - i;
        __int128_t contribution = (__int128_t)coords[i] * (count_smaller - count_larger);
        total_diff += contribution;
    }
    
    return total_diff;
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
        __int128_t sum_x = calc_dimension_sum(x);
        __int128_t sum_y = calc_dimension_sum(y);

        print128(sum_x + sum_y);
    }
    return 0;
}