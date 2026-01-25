#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct HashBIT {
    int n;
    ll MOD, BASE;
    vector<ll> powers;
    vector<ll> fwd_bit;
    vector<ll> rev_bit;

    HashBIT(int len, ll m, ll b, const string &s) {
        n = len;
        MOD = m;
        BASE = b;
        powers.resize(n + 2);
        powers[0] = 1;
        for (int i = 1; i <= n + 1; i++) {
            powers[i] = (powers[i - 1] * BASE) % MOD;
        }
        fwd_bit.assign(n + 1, 0);
        rev_bit.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int charVal = s[i - 1] - 'a' + 1;
            _update_bit(fwd_bit, i, (charVal * powers[i]) % MOD);
            _update_bit(rev_bit, i, (charVal * powers[n - i + 1]) % MOD);
        }
    }
    void _update_bit(vector<ll> &tree, int idx, ll val) {
        val = (val % MOD + MOD) % MOD; 
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] = (tree[idx] + val) % MOD;
        }
    }
    ll _query_bit(const vector<ll> &tree, int idx) {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum = (sum + tree[idx]) % MOD;
        }
        return sum;
    }
    ll getRangeSum(const vector<ll> &tree, int l, int r) {
        ll res = _query_bit(tree, r) - _query_bit(tree, l - 1);
        return (res % MOD + MOD) % MOD;
    }
    void update(int k, int oldCharVal, int newCharVal) {
        ll diff = (newCharVal - oldCharVal);
        ll fwd_diff = (diff * powers[k]) % MOD;
        _update_bit(fwd_bit, k, fwd_diff);
        ll rev_diff = (diff * powers[n - k + 1]) % MOD;
        _update_bit(rev_bit, k, rev_diff);
    }

    bool isPalindrome(int a, int b) {
        ll h1 = getRangeSum(fwd_bit, a, b);
        ll h2 = getRangeSum(rev_bit, a, b);        
        ll term1 = (h1 * powers[n - b + 1]) % MOD;
        ll term2 = (h2 * powers[a]) % MOD;

        return term1 == term2;
    }
};

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    string s;
    cin >> s;

    HashBIT hasher1(n, 1e9 + 7, 37, s);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            char x;
            cin >> k >> x;
            int oldVal = s[k - 1] - 'a' + 1;
            int newVal = x - 'a' + 1;
            
            hasher1.update(k, oldVal, newVal);
            s[k - 1] = x;
        } else {
            int a, b;
            cin >> a >> b;
            if (hasher1.isPalindrome(a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}