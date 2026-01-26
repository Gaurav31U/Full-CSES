#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
};
long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool on_segment(Point a, Point b, Point p) {
    return (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
            p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y));
}

void solve() {
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    long long d1 = cross_product(p1, p2, p3);
    long long d2 = cross_product(p1, p2, p4);
    long long d3 = cross_product(p3, p4, p1);
    long long d4 = cross_product(p3, p4, p2);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        cout << "YES\n";
        return;
    }
    if (d1 == 0 && on_segment(p1, p2, p3)) { cout << "YES\n"; return; }
    if (d2 == 0 && on_segment(p1, p2, p4)) { cout << "YES\n"; return; }
    if (d3 == 0 && on_segment(p3, p4, p1)) { cout << "YES\n"; return; }
    if (d4 == 0 && on_segment(p3, p4, p2)) { cout << "YES\n"; return; }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}