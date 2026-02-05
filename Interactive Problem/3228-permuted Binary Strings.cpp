#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin >> n;
    vector<int> p(n, 0);

    for (int bit = 0; (1 << bit) < n; ++bit) {
        string query = "";
        query.reserve(n);
        for (int j = 0; j < n; ++j) {
            if ((j >> bit) & 1) {
                query += '1';
            } else {
                query += '0';
            }
        }
        
        cout << "? " << query << endl;
        
        string response;
        cin >> response;
        
        if (response.size() != n) return 0;
        for (int i = 0; i < n; ++i) {
            if (response[i] == '1') {
                p[i] |= (1 << bit);
            }
        }
    }
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << p[i] + 1;
    }
    cout << endl;

    return 0;
}