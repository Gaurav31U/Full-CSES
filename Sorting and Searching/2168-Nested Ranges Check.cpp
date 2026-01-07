#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Range {
    int x, y, id;
};
bool compareRanges(const Range& a, const Range& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y > b.y;
}
int main() {
    int n;cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].id = i;
    }
    sort(ranges.begin(), ranges.end(), compareRanges);
    vector<int> contains_another(n, 0);
    vector<int> is_contained(n, 0);
    int max_y = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].y <= max_y) {
            is_contained[ranges[i].id] = 1;
        }
        max_y = max(max_y, ranges[i].y);
    }
    int min_y = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (ranges[i].y >= min_y) {
            contains_another[ranges[i].id] = 1;
        }
        min_y = min(min_y, ranges[i].y);
    }
    for (int i = 0; i < n; i++) {
        cout << contains_another[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << is_contained[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}