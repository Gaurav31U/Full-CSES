#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> rank(n + 1);
    for (int i = 0; i < n; ++i) {
        rank[p[i]] = i;
    }
    rank[n] = -1;

    string s(n, ' ');
    char cur_char = 'a';
    s[p[0]] = cur_char;

    for (int i = 0; i < n - 1; ++i) {
        int u = p[i];
        int v = p[i + 1];
        if (rank[u + 1] > rank[v + 1]) {
            cur_char++;
        }
        if (cur_char > 'z') {
            cout << -1 << endl;
            return;
        }
        s[v] = cur_char;
    }
    cout << s << endl;
}
int main() {
    solve();
    return 0;
}