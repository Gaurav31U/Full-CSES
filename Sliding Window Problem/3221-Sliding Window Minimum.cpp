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
    
    vector<int> dq(n);
    int head = 0;
    int tail = 0;

    long long xor_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (head < tail && dq[head] == i - k) 
            head++;

        while (head < tail && arr[dq[tail-1]] >= arr[i]) 
            tail--;

        dq[tail++] = i;

        if (i >= k - 1) 
            xor_sum ^= arr[dq[head]];
        
    }
    cout << xor_sum << endl;
    return 0;
}