#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
};
bool compareX(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), compareX);
    set<pair<long long, long long>> active_strip;

    long long min_d2 = 8000000000000000005LL; 
    
    int left = 0;
    for (int i = 0; i < n; ++i) {
        long long current_x = points[i].x;
        long long current_y = points[i].y;
        while (left < i) {
            long long dx = current_x - points[left].x;
            if (dx * dx >= min_d2) {
                active_strip.erase({points[left].y, points[left].x});
                left++;
            } else {
                break;
            }
        }
        long long d_limit = (long long)ceil(sqrt((double)min_d2));
        auto it = active_strip.lower_bound({current_y - d_limit, -4000000000000000000LL}); 

        while (it != active_strip.end()) {
            long long y_other = it->first;
            long long x_other = it->second;
            if (y_other > current_y + d_limit) break;

            long long dx = current_x - x_other;
            long long dy = current_y - y_other;
            long long dist_sq = dx * dx + dy * dy;

            if (dist_sq < min_d2) {
                min_d2 = dist_sq;
                d_limit = (long long)ceil(sqrt((double)min_d2)); 
            }
            it++;
        }
        active_strip.insert({current_y, current_x});
    }
    cout << min_d2 << endl;
    return 0;
}