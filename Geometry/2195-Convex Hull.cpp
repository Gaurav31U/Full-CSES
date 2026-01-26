#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};
long long cross_product(const Point& o, const Point& a, const Point& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    vector<Point> hull;
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2) {
            long long cp = cross_product(hull[hull.size() - 2], hull.back(), points[i]);
            if (cp < 0) { 
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(points[i]);
    }
    int lower_limit = hull.size(); 
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > lower_limit) {
            long long cp = cross_product(hull[hull.size() - 2], hull.back(), points[i]);
            if (cp < 0) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(points[i]);
    }
    hull.erase(unique(hull.begin(), hull.end()), hull.end());
    hull.pop_back();
    cout << hull.size() << "\n";
    for (const auto& p : hull) {
        cout << p.x << " " << p.y << "\n";
    }
    return 0;
}