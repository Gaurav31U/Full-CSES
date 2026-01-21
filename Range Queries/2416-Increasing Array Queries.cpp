#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
const int LOGN = 20;
int n, q;
int x[MAXN];
int nxt[MAXN];     
int up[MAXN][LOGN];   
ll cost_sum[MAXN][LOGN];
ll pref[MAXN]; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n >> q)) return 0;
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pref[i] = pref[i-1] + x[i];
    }
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && x[s.top()] < x[i]) {
            nxt[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        nxt[s.top()] = n + 1;
        s.pop();
    }
    nxt[n + 1] = n + 1;
    x[n + 1] = 0;
    for (int i = 1; i <= n + 1; i++) {
        up[i][0] = nxt[i];
        if (i <= n) {
            cost_sum[i][0] = (ll)x[i] * (nxt[i] - i);
        } else {
            cost_sum[i][0] = 0;
        }
    }
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= n + 1; i++) {
            int mid = up[i][j-1];
            up[i][j] = up[mid][j-1];
            cost_sum[i][j] = cost_sum[i][j-1] + cost_sum[mid][j-1];
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        int curr = a;
        ll max_seq_sum = 0;
        for (int j = LOGN - 1; j >= 0; j--) {
            if (up[curr][j] <= b) {
                max_seq_sum += cost_sum[curr][j];
                curr = up[curr][j];
            }
        }
        max_seq_sum += (ll)x[curr] * (b - curr + 1);
        ll original_sum = pref[b] - pref[a-1];
        cout << (max_seq_sum - original_sum) << "\n";
    }
    return 0;
}