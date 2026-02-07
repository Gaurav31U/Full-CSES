#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct Pt {
    int r, c;
};

inline int dist(const Pt& a, const Pt& b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

inline bool check_parity(int h, int w, Pt s, Pt t) {
    long long area = 1LL * h * w;
    if ((area - 1) % 2 != dist(s, t) % 2) return false;
    if (area % 2 != 0) {
        if ((s.r + s.c) % 2 != 0) return false;
        if ((t.r + t.c) % 2 != 0) return false;
    }
    return true;
}

bool solve(int h, int w, Pt s, Pt t, string& res) {
    if (!check_parity(h, w, s, t)) return false;

    if (h == 1) {
        if (s.c == 0 && t.c == w - 1) { res.append(w - 1, 'R'); return true; }
        if (s.c == w - 1 && t.c == 0) { res.append(w - 1, 'L'); return true; }
        return false;
    }
    if (w == 1) {
        if (s.r == 0 && t.r == h - 1) { res.append(h - 1, 'D'); return true; }
        if (s.r == h - 1 && t.r == 0) { res.append(h - 1, 'U'); return true; }
        return false;
    }

    int rmin = min(s.r, t.r), rmax = max(s.r, t.r);
    int cmin = min(s.c, t.c), cmax = max(s.c, t.c);
    
    bool can_h = (rmin < rmax);
    bool can_v = (cmin < cmax);
    
    int primary = -1;
    if (can_h && can_v) primary = (h >= w) ? 0 : 1;
    else if (can_h) primary = 0;
    else if (can_v) primary = 1;
    
    int modes[2];
    int cnt = 0;
    if (primary != -1) modes[cnt++] = primary;
    if (can_h && can_v) modes[cnt++] = 1 - primary;

    for (int z = 0; z < cnt; ++z) {
        int m = modes[z];
        
        int start = (m == 0) ? rmin : cmin;
        int end = (m == 0) ? rmax : cmax;
        int len = (m == 0) ? h : w;
        
        int k = max(start, min(end - 1, (len - 1) / 2));
        
        bool s_in_1 = (m == 0) ? (s.r <= k) : (s.c <= k);
        int b_len = (m == 0) ? w : h;
        int mid = b_len / 2;
        
        for (int d = 0; ; ++d) {
            int attempts[] = {mid + d, mid - d};
            int n_atts = (d == 0) ? 1 : 2;
            bool valid_idx = false;
            
            for (int j = 0; j < n_atts; ++j) {
                int i = attempts[j];
                if (i < 0 || i >= b_len) continue;
                valid_idx = true;
                
                int h1, w1, h2, w2;
                Pt s1, t1, s2, t2; 
                char glue;
                
                if (m == 0) { 
                    h1 = k + 1; w1 = w;
                    h2 = h - 1 - k; w2 = w;
                    Pt u = {k, i}; Pt v = {0, i};
                    if (s_in_1) {
                        s1 = s; t1 = u; s2 = v; t2 = {t.r - (k + 1), t.c}; glue = 'D';
                    } else {
                        s2 = {s.r - (k + 1), s.c}; t2 = v; s1 = u; t1 = t; glue = 'U';
                    }
                } else {
                    h1 = h; w1 = k + 1;
                    h2 = h; w2 = w - 1 - k;
                    Pt u = {i, k}; Pt v = {i, 0};
                    if (s_in_1) {
                        s1 = s; t1 = u; s2 = v; t2 = {t.r, t.c - (k + 1)}; glue = 'R';
                    } else {
                        s2 = {s.r, s.c - (k + 1)}; t2 = v; s1 = u; t1 = t; glue = 'L';
                    }
                }
                
                if (check_parity(h1, w1, s1, t1) && check_parity(h2, w2, s2, t2)) {
                    string p1, p2;
                    bool possible = false;
                    if (s_in_1) {
                        if (solve(h1, w1, s1, t1, p1) && solve(h2, w2, s2, t2, p2)) {
                            res = p1 + glue + p2;
                            possible = true;
                        }
                    } else {
                        if (solve(h2, w2, s2, t2, p2) && solve(h1, w1, s1, t1, p1)) {
                            res = p2 + glue + p1;
                            possible = true;
                        }
                    }
                    if (possible) return true;
                }
            }
            if (!valid_idx) break;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    if (cin >> t) {
        while (t--) {
            int n, m, r1, c1, r2, c2;
            cin >> n >> m >> r1 >> c1 >> r2 >> c2;
            string ans;
            Pt s = {r1 - 1, c1 - 1};
            Pt end = {r2 - 1, c2 - 1};
            if (solve(n, m, s, end, ans)) {
                cout << "YES\n" << ans << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}