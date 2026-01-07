#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 3000;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    string ans = "";
    ans += grid[0][0];
    vector<pair<int, int>> q;
    q.push_back({0, 0});
    vis[0][0] = true;
    for (int k = 0; k < 2 * n - 2; k++) {
        char min_char = 'Z' + 1;
        for (auto& p : q) {
            int r = p.first;
            int c = p.second;
            if (c + 1 < n) min_char = min(min_char, grid[r][c + 1]);
            if (r + 1 < n) min_char = min(min_char, grid[r + 1][c]);
        }
        ans += min_char;
        vector<pair<int, int>> next_q;
        for (auto& p : q) {
            int r = p.first;
            int c = p.second;
            if (c + 1 < n && !vis[r][c + 1] && grid[r][c + 1] == min_char) {
                vis[r][c + 1] = true;
                next_q.push_back({r, c + 1});
            }
            if (r + 1 < n && !vis[r + 1][c] && grid[r + 1][c] == min_char) {
                vis[r + 1][c] = true;
                next_q.push_back({r + 1, c});
            }
        }
        q = move(next_q);
    }
    cout << ans << endl;
    return 0;
}