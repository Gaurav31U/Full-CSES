#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;cin >> s;

        string t = "^";
        t.reserve(2 * s.length() + 3);
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        int n = t.length();
        vector<int> P(n, 0); 
        int C = 0,R = 0; 

        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i; 
            if (R > i) P[i] = min(R - i, P[i_mirror]);
            
            while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) P[i]++;
            
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        int maxLen = 0,centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - 1 - maxLen) / 2;
        cout << s.substr(start, maxLen) << "\n";
    return 0;
}