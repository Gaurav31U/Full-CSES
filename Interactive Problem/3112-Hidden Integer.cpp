#include <bits/stdc++.h>
using namespace std;
int main() {
    int l = 1;
    int r = 1000000000;
    while (l < r) {
        int mid = l + (r - l) / 2;
        cout << "? " << mid << endl;

        string response;
        cin >> response;

        if (response == "YES") {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << "! " << l << endl;
    return 0;
}