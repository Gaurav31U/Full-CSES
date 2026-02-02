#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
struct Line {
    ll m, c;
    ll eval(ll x) { return m * x + c; }
};
bool isRedundant(const Line& l1, const Line& l2, const Line& l3) {
    return (__int128)(l2.c - l1.c) * (l2.m - l3.m) >= 
           (__int128)(l3.c - l2.c) * (l1.m - l2.m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;cin >> n >> k;
    vector<ll> x(n + 1);
    vector<ll> S(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        S[i] = S[i-1] + x[i];
    }
    if(k==1){
        cout<<(S[n]*S[n]);
        return 0;
    }
    vector<ll> dp(n + 1, 0);
    vector<ll> prev_dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prev_dp[i] = S[i] * S[i];
    }
    for (int split = 2; split <= k; split++) {
        deque<Line> dq;
        int initial_p = split - 1;
        dq.push_back({ -2 * S[initial_p], prev_dp[initial_p] + S[initial_p] * S[initial_p] });
        for (int i = split; i <= n; i++) {
            while (dq.size() >= 2 && dq[0].eval(S[i]) >= dq[1].eval(S[i])) {
                dq.pop_front();
            }
            dp[i] = dq[0].eval(S[i]) + S[i] * S[i];
            Line newLine = { -2 * S[i], prev_dp[i] + S[i] * S[i] };
            while (dq.size() >= 2 && isRedundant(dq[dq.size() - 2], dq.back(), newLine)) {
                dq.pop_back();
            }
            dq.push_back(newLine);
        }
        prev_dp = dp;
    }
    cout << dp[n] << endl;
    return 0;
}