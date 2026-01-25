#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;cin>>s;
        int n = s.length();
        if (n <= 1) {
            cout << s << endl;
            return 0;
        }
        string ss = s + s;
        int i = 0, j = 1, k = 0;
        
        while (i < n && j < n && k < n) {
            int diff = ss[i + k] - ss[j + k];
            
            if (diff == 0) {
                k++;
            } else {
                if (diff > 0) {
                    i += k + 1;
                } else {
                    j += k + 1;
                }
                if (i == j) {
                    j++;
                }
                k = 0;
            }
        }
        int start = min(i, j);
        cout << ss.substr(start, n) << endl;
    return 0;
}