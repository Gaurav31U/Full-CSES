#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    if (!(cin >> s)) return 0;
    long long k;
    cin >> k;
    s += '$';
    int n = s.size();

    vector<int> p(n), c(n);

    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k_trans = 0;
    while ((1 << k_trans) < n) {
        vector<int> pn(n);
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << k_trans);
            if (pn[i] < 0) pn[i] += n;
        }

        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1];

        vector<int> p_new(n);
        for (int i = 0; i < n; i++) {
            p_new[pos[c[pn[i]]]++] = pn[i];
        }
        p = p_new;

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k_trans)) % n]};
            pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << k_trans)) % n]};
            if (curr == prev) c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k_trans++;
    }

    vector<int> lcp(n);
    int k_lcp = 0;
    for (int i = 0; i < n; i++) { 
        int pi = c[i]; 
        if (pi > 0) {
            int j = p[pi - 1]; 
            while (s[i + k_lcp] == s[j + k_lcp]) {
                k_lcp++;
            }
            lcp[pi] = k_lcp;
            if (k_lcp > 0) k_lcp--;
        }
    }
    for (int i = 0; i < n; i++) {
        long long suffix_len = (long long)n - 1 - p[i];
        if (suffix_len <= 0) continue; 
        int common = lcp[i]; 
        long long distinct_new = suffix_len - common;
        if (distinct_new <= 0) continue; 
        if (k <= distinct_new) {
            cout << s.substr(p[i], common + k) << "\n";
            return 0;
        } else {
            k -= distinct_new;
        }
    }
    return 0;
}