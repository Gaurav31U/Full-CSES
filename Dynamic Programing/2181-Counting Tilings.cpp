#include <iostream>
#include <vector>
using namespace std;
int N, M;
long long dp[1001][1024];
const int MOD = 1e9 + 7;
void generate_next_masks(int col, int row, int mask, int next_mask, long long current_ways) {
    if (row == N) {
        dp[col + 1][next_mask] = (dp[col + 1][next_mask] + current_ways) % MOD;
        return;
    }
    if (mask & (1 << row)) {
        generate_next_masks(col, row + 1, mask, next_mask, current_ways);
    } else {
        generate_next_masks(col, row + 1, mask, next_mask | (1 << row), current_ways);
        if (row + 1 < N && !(mask & (1 << (row + 1)))) {
            generate_next_masks(col, row + 2, mask, next_mask, current_ways);
        }
    }
}
int main() {
    if (!(cin >> N >> M)) return 0;
    if ((N * M) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (int col = 0; col < M; col++) {
        for (int mask = 0; mask < (1 << N); mask++) {
            if (dp[col][mask] > 0) {
                generate_next_masks(col, 0, mask, 0, dp[col][mask]);
            }
        }
    }
    cout << dp[M][0] << endl;
    return 0;
}