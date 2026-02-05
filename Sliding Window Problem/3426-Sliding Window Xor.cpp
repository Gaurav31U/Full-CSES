#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr(n);
    
    arr[0] = (int)x;
    for (int i = 1; i < n; ++i) 
        arr[i] = (int)((a * arr[i-1] + b) % c);
    
    int current_window_xor = 0;
    for (int i = 0; i < k; ++i) 
        current_window_xor ^= arr[i];
    
    int total_xor_sum = current_window_xor;

    for (int i = 0; i < n - k; ++i) {
        current_window_xor = current_window_xor ^ arr[i] ^ arr[i+k];
        total_xor_sum ^= current_window_xor;
    }
    cout << total_xor_sum << "\n";
    return 0;
}