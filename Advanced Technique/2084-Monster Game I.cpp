#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Line {
    ll m, c;
    ll eval(ll x) { return m * x + c; }
};
deque<Line> hull;
bool isRedundant(const Line& l1, const Line& l2, const Line& l3) {
    return (__int128)(l3.c - l2.c) * (l1.m - l2.m) <= 
           (__int128)(l2.c - l1.c) * (l2.m - l3.m);
}
void addLine(ll m, ll c) {
    Line newLine = {m, c};
    if (!hull.empty() && hull.back().m == m) {
        if (hull.back().c > c) hull.pop_back();
        else return; 
    }
    while (hull.size() >= 2 && isRedundant(hull[hull.size()-2], hull.back(), newLine)) {
        hull.pop_back();
    }
    hull.push_back(newLine);
}
ll query(ll x) {
    while (hull.size() >= 2 && hull[0].eval(x) >= hull[1].eval(x)) {
        hull.pop_front();
    }
    return hull[0].eval(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll x;
    if (cin >> n >> x) {
        vector<ll> s(n);
        vector<ll> f(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++) cin >> f[i];
        addLine(x, 0);
        ll currentDP = 0;
        for (int i = 0; i < n; i++) {
            currentDP = query(s[i]);
            addLine(f[i], currentDP);
        }
        cout << currentDP << endl;
    }
    return 0;
}