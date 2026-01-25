#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    if (!(cin >> s)) return;
    int n = s.length();
    s += '$';
    int n_s = s.length();
    vector<int> p(n_s), c(n_s);

    {
        vector<pair<char, int>> a(n_s);
        for (int i = 0; i < n_s; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for (int i = 0; i < n_s; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n_s; i++) {
            if (a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
            else c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n_s) {
        vector<int> pn(n_s);
        for (int i = 0; i < n_s; i++) {
            pn[i] = p[i] - (1 << k);
            if (pn[i] < 0) pn[i] += n_s;
        }
        vector<int> cnt(n_s, 0);
        for (int i = 0; i < n_s; i++) cnt[c[pn[i]]]++;
        
        vector<int> pos(n_s);
        pos[0] = 0;
        for (int i = 1; i < n_s; i++) pos[i] = pos[i - 1] + cnt[i - 1];

        vector<int> new_p(n_s);
        for (int i = 0; i < n_s; i++) {
            new_p[pos[c[pn[i]]]++] = pn[i];
        }
        p = new_p;

        vector<int> new_c(n_s);
        new_c[p[0]] = 0;
        for (int i = 1; i < n_s; i++) {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n_s]};
            pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << k)) % n_s]};
            if (curr == prev) new_c[p[i]] = new_c[p[i - 1]];
            else new_c[p[i]] = new_c[p[i - 1]] + 1;
        }
        c = new_c;
        k++;
    }
    vector<int> rank(n_s);
    for (int i = 0; i < n_s; i++) rank[p[i]] = i;

    vector<int> lcp(n_s);
    int current_len = 0;

    for (int i = 0; i < n_s; i++) {
        if (rank[i] == 0) {
            current_len = 0;
            continue;
        }
        int j = p[rank[i] - 1];
        while (i + current_len < n_s && j + current_len < n_s && s[i + current_len] == s[j + current_len]) {
            current_len++;
        }
        lcp[rank[i]] = current_len;
        if (current_len > 0) current_len--;
    }
    vector<int> diff(n + 2, 0);
    for (int i = 1; i < n_s; i++) {
        int suffix_len = (n_s - 1) - p[i];
        if (suffix_len > 0) {
            int low = lcp[i] + 1;
            int high = suffix_len;
            
            if (low <= high) {
                diff[low]++;
                diff[high + 1]--;
            }
        }
    }
    int current_cnt = 0;
    for (int len = 1; len <= n; len++) {
        current_cnt += diff[len];
        cout << current_cnt << (len == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}