#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> arr(n);
    
    arr[0] = x;
    for (int i = 1; i < n; ++i) 
        arr[i] = (a * arr[i-1] + b) % c;
    
    long long current_sum = 0;
    for (int i = 0; i < k; ++i) 
        current_sum += arr[i];
    
    long long xor_sum = current_sum;

    for (int i = 0; i < n - k; ++i) {
        current_sum = current_sum - arr[i] + arr[i+k];
        xor_sum ^= current_sum;
    }
    cout << xor_sum << endl;
    return 0;
}