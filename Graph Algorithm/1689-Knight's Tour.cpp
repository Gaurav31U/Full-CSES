#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 8;
int board[N][N];
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool is_valid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[y][x] == 0);
}
int get_degree(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (is_valid(x + dx[i], y + dy[i])) {
            count++;
        }
    }
    return count;
}
struct Move {
    int x, y, degree;
    bool operator<(const Move& other) const {
        return degree < other.degree;
    }
};

bool solve(int x, int y, int step) {
    board[y][x] = step;
    if (step == N * N) return true;
    vector<Move> next_moves;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny)) {
            next_moves.push_back({nx, ny, get_degree(nx, ny)});
        }
    }

    // Sort neighbors by their degree (Warnsdorff's Rule)
    sort(next_moves.begin(), next_moves.end());

    for (auto& next : next_moves) {
        if (solve(next.x, next.y, step + 1)) return true;
    }
    board[y][x] = 0;
    return false;
}
int main() {
    int start_x, start_y;
    if (!(cin >> start_x >> start_y)) return 0;
    int sx = start_x - 1;
    int sy = start_y - 1;
    if (solve(sx, sy, 1)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}