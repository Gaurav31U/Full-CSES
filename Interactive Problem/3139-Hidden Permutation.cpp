#include <bits/stdc++.h>
using namespace std;
bool compare(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string response;
    cin >> response;
    return response == "YES";
}
int main() {
    int n;cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1); 
    stable_sort(p.begin(), p.end(), compare);

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[p[i] - 1] = i + 1;
    }
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << result[i];
    }
    return 0;
}