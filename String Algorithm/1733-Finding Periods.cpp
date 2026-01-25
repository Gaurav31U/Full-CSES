#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    if (cin >> s) {
        int n = s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }

        vector<int> periods;
        int len = pi[n - 1];
        
        while (len > 0) {
            periods.push_back(n - len);
            len = pi[len - 1];
        }
        periods.push_back(n);
        for (size_t i = 0; i < periods.size(); i++) {
            cout << periods[i] << " ";
        }
    }
    return 0;
}