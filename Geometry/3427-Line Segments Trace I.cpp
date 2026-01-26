#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Line {
    ll k, b;
    ll eval(ll x) const { return k * x + b; }
};
bool is_bad(const Line& prev, const Line& mid, const Line& next) {
    return (prev.b - mid.b) * (next.k - mid.k) >= (mid.b - next.b) * (mid.k - prev.k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll m;cin >> n >> m;
    vector<Line> lines;
    lines.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll y1, y2;
        cin >> y1 >> y2;
        ll k = (y2 - y1) / m;
        ll b = y1;
        lines.push_back({k, b});
    }
    sort(lines.begin(), lines.end(), [](const Line& a, const Line& b) {
        if (a.k != b.k) return a.k < b.k;
        return a.b > b.b;
    });
    vector<Line> hull;
    for (const auto& ln : lines) {
        if (!hull.empty() && hull.back().k == ln.k) {
            continue;
        }
        while (hull.size() >= 2) {
            if (is_bad(hull[hull.size()-2], hull.back(), ln)) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(ln);
    }
    int ptr = 0;
    for (int x = 0; x <= m; ++x) {
        while (ptr + 1 < (int)hull.size()) {
            if (hull[ptr+1].eval(x) >= hull[ptr].eval(x)) {
                ptr++;
            } else {
                break;
            }
        }
        cout << hull[ptr].eval(x) << (x == m ? "" : " ");
    }
    cout << "\n";

    return 0;
}