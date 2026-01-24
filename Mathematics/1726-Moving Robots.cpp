#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    if (cin >> k) {
        double robot_probs[64][64];
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int start_node = 0; start_node < 64; ++start_node) {
            int start_r = start_node / 8;
            int start_c = start_node % 8;
            double dp[8][8];
            for(int r = 0; r < 8; ++r) 
                for(int c = 0; c < 8; ++c) 
                    dp[r][c] = 0.0;
            
            dp[start_r][start_c] = 1.0;

            for (int step = 0; step < k; ++step) {
                double next_dp[8][8];
                for(int r = 0; r < 8; ++r) 
                    for(int c = 0; c < 8; ++c) 
                        next_dp[r][c] = 0.0;
                
                for (int r = 0; r < 8; ++r) {
                    for (int c = 0; c < 8; ++c) {
                        if (dp[r][c] > 0.0) {

                            int neighbor_r[4];
                            int neighbor_c[4];
                            int valid_count = 0;
                            
                            for (int i = 0; i < 4; ++i) {
                                int nr = r + dr[i];
                                int nc = c + dc[i];
                                if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
                                    neighbor_r[valid_count] = nr;
                                    neighbor_c[valid_count] = nc;
                                    valid_count++;
                                }
                            }
                            
                            double share = dp[r][c] / valid_count;
                            for (int i = 0; i < valid_count; ++i) {
                                next_dp[neighbor_r[i]][neighbor_c[i]] += share;
                            }
                        }
                    }
                }
                
                for (int r = 0; r < 8; ++r)
                    for (int c = 0; c < 8; ++c)
                        dp[r][c] = next_dp[r][c];
            }

            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    robot_probs[start_node][r * 8 + c] = dp[r][c];
                }
            }
        }
        double expected_empty_squares = 0.0;
        for (int target = 0; target < 64; ++target) {
            double prob_empty = 1.0;
            for (int start_node = 0; start_node < 64; ++start_node) {
                prob_empty *= (1.0 - robot_probs[start_node][target]);
            }
            
            expected_empty_squares += prob_empty;
        }
        cout << fixed << setprecision(6) << expected_empty_squares << endl;
    }
    
    return 0;
}