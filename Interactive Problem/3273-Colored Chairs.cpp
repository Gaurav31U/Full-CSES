#include <iostream>
using namespace std;
char ask(int i) {
    cout << "? " << i << endl;
    char color;
    cin >> color;
    return color;
}
int main() {
    int n;cin >> n;
    char c1 = ask(1);
    int L = 1;
    int R = n + 1;
    char cL = c1;
    char cR = c1; 

    while (R - L > 1) {
        int mid = L + (R - L) / 2;
        char cMid = ask(mid);

        int dist = mid - L;
        bool same_color = (cL == cMid);
        bool expected_same_if_alternating = (dist % 2 == 0);

        if (same_color != expected_same_if_alternating) {
            R = mid;
            cR = cMid;
        } else {
            L = mid;
            cL = cMid;
        }
    }
    cout << "! " << L << endl;
    return 0;
}