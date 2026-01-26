#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
};
bool is_on_segment(Point p1, Point p2, Point p) {
    long long cp = (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x);
    if (cp != 0) return false;
    long long min_x = min(p1.x, p2.x);
    long long max_x = max(p1.x, p2.x);
    long long min_y = min(p1.y, p2.y);
    long long max_y = max(p1.y, p2.y);
    if (p.x >= min_x && p.x <= max_x && p.y >= min_y && p.y <= max_y) {
        return true;
    }
    return false;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    for (int i = 0; i < m; ++i) {
        Point p;
        cin >> p.x >> p.y;
        
        bool on_boundary = false;
        int intersection_count = 0;
        
        for (int j = 0; j < n; ++j) {
            Point p1 = polygon[j];
            Point p2 = polygon[(j + 1) % n]; 
            if (is_on_segment(p1, p2, p)) {
                on_boundary = true;
                break;
            }
            bool straddles = (p1.y > p.y) != (p2.y > p.y);
            
            if (straddles) {
                long long cp = (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x);
                if (p2.y > p1.y) {
                    if (cp > 0) intersection_count++;
                } else {
                    if (cp < 0) intersection_count++;
                }
            }
        }
        
        if (on_boundary) {
            cout << "BOUNDARY\n";
        } else if (intersection_count % 2 != 0) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}