#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Range {
    int x, y, id;
};
struct FenwickTree {
    int size;
    vector<int> tree;
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (; i <= size; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
int main() {
    int n;cin >> n;
    vector<Range> ranges(n);
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].id = i;
        coords.push_back(ranges[i].y);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    auto get_rank = [&](int y) {
        return lower_bound(coords.begin(), coords.end(), y) - coords.begin() + 1;
    };
    sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });
    vector<int> contains_count(n), is_contained_count(n);
    int m = coords.size();
    FenwickTree ft1(m), ft2(m);
    for (int i = 0; i < n; i++) {
        int r = get_rank(ranges[i].y);
        is_contained_count[ranges[i].id] = ft1.query(r, m);
        ft1.add(r, 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        int r = get_rank(ranges[i].y);
        contains_count[ranges[i].id] = ft2.query(1, r);
        ft2.add(r, 1);
    }
    for (int i = 0; i < n; i++) cout << contains_count[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
    for (int i = 0; i < n; i++) cout << is_contained_count[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
    return 0;
}