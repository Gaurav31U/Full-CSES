#include <bits/stdc++.h>
using namespace std;

int grid_ids[105][105]; 
int n_global, m_global;
int current_tromino_id;

int kernel_9x5[9][5];
bool kernel_computed = false;

bool generate_kernel_9x5(int filled_count) {
    if (filled_count == 45) return true;

    int r = -1, c = -1;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (kernel_9x5[i][j] == 0) {
                r = i; c = j;
                break;
            }
        }
        if (r != -1) break;
    }

    if (r+1<9 && c+1<5 && kernel_9x5[r+1][c]==0 && kernel_9x5[r+1][c+1]==0) {
        kernel_9x5[r][c] = kernel_9x5[r+1][c] = kernel_9x5[r+1][c+1] = filled_count + 1;
        if (generate_kernel_9x5(filled_count + 3)) return true;
        kernel_9x5[r][c] = kernel_9x5[r+1][c] = kernel_9x5[r+1][c+1] = 0;
    }
    if (r+1<9 && c+1<5 && kernel_9x5[r][c+1]==0 && kernel_9x5[r+1][c+1]==0) {
        kernel_9x5[r][c] = kernel_9x5[r][c+1] = kernel_9x5[r+1][c+1] = filled_count + 1;
        if (generate_kernel_9x5(filled_count + 3)) return true;
        kernel_9x5[r][c] = kernel_9x5[r][c+1] = kernel_9x5[r+1][c+1] = 0;
    }
    if (r+1<9 && c+1<5 && kernel_9x5[r][c+1]==0 && kernel_9x5[r+1][c]==0) {
        kernel_9x5[r][c] = kernel_9x5[r][c+1] = kernel_9x5[r+1][c] = filled_count + 1;
        if (generate_kernel_9x5(filled_count + 3)) return true;
        kernel_9x5[r][c] = kernel_9x5[r][c+1] = kernel_9x5[r+1][c] = 0;
    }
    if (r+1<9 && c-1>=0 && kernel_9x5[r+1][c]==0 && kernel_9x5[r+1][c-1]==0) {
        kernel_9x5[r][c] = kernel_9x5[r+1][c] = kernel_9x5[r+1][c-1] = filled_count + 1;
        if (generate_kernel_9x5(filled_count + 3)) return true;
        kernel_9x5[r][c] = kernel_9x5[r+1][c] = kernel_9x5[r+1][c-1] = 0;
    }

    return false;
}
void add_tromino(vector<pair<int, int>> cells) {
    current_tromino_id++;
    for (auto p : cells) {
        grid_ids[p.first][p.second] = current_tromino_id;
    }
}

void fill_2x3(int r, int c) {
    add_tromino({{r, c}, {r, c+1}, {r+1, c}}); 
    add_tromino({{r, c+2}, {r+1, c+1}, {r+1, c+2}});
}

void fill_3x2(int r, int c) {
    add_tromino({{r, c}, {r, c+1}, {r+1, c}});
    add_tromino({{r+1, c+1}, {r+2, c}, {r+2, c+1}});
}

void solve_even(int r_off, int c_off, int h, int w) {
    int current_w = w;
    int current_c = c_off;
    
    while (current_w % 3 != 0) {
        for (int i = 0; i < h; i += 3) {
            fill_3x2(r_off + i, current_c);
        }
        current_c += 2;
        current_w -= 2;
    }
    
    for (int i = 0; i < h; i += 2) {
        for (int j = 0; j < current_w; j += 3) {
            fill_2x3(r_off + i, current_c + j);
        }
    }
}

void solve_9x5_block(int r_off, int c_off) {
    map<int, int> id_map;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<5; ++j) {
            int local_id = kernel_9x5[i][j];
            if (id_map.find(local_id) == id_map.end()) {
                current_tromino_id++;
                id_map[local_id] = current_tromino_id;
            }
            grid_ids[r_off + i][c_off + j] = id_map[local_id];
        }
    }
}

void solve_odd_odd(int r_off, int c_off, int h, int w) {
    int cur_h = h;
    int cur_w = w;
    int r = r_off;
    int c = c_off;
    while (cur_w > 5) {
        for (int i = 0; i < cur_h; i += 3) {
            fill_3x2(r + i, c);
        }
        c += 2;
        cur_w -= 2;
    }

    while (cur_h > 9) {
        solve_even(r, c, 6, 5);
        r += 6;
        cur_h -= 6;
    }
    solve_9x5_block(r, c);
}

void solve_test() {
    int n, m;cin >> n >> m;

    long long area = (long long)n * m;
    bool impossible = false;

    if (area % 3 != 0) impossible = true;
    else if (n == 1 || m == 1) impossible = true;
    else if (min(n, m) == 2 && max(n, m) % 3 != 0) impossible = true; 
    else if ((n == 3 && m % 2 != 0) || (m == 3 && n % 2 != 0)) impossible = true;
    
    if (impossible) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    n_global = n; m_global = m;
    current_tromino_id = 0;
    memset(grid_ids, 0, sizeof(grid_ids));

    if (!kernel_computed) {
        memset(kernel_9x5, 0, sizeof(kernel_9x5));
        generate_kernel_9x5(0);
        kernel_computed = true;
    }

    if (n % 2 == 0) {
        solve_even(0, 0, n, m);
    }
    else if (m % 2 == 0) {
        swap(n, m);
        solve_even(0, 0, n, m);
        swap(n, m);
        int temp[105][105];
        for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) temp[i][j] = grid_ids[j][i]; 
        
        memset(grid_ids, 0, sizeof(grid_ids));
        for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) grid_ids[i][j] = temp[i][j];
    }
    else {
        if (n % 3 == 0) {
            solve_odd_odd(0, 0, n, m);
        } else {
            swap(n, m);
            solve_odd_odd(0, 0, n, m);
            swap(n, m);
            int temp[105][105];
            for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) temp[i][j] = grid_ids[j][i];
            memset(grid_ids, 0, sizeof(grid_ids));
            for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) grid_ids[i][j] = temp[i][j];
        }
    }

    vector<string> result_grid(n_global, string(m_global, '.'));
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int i = 0; i < n_global; ++i) {
        for (int j = 0; j < m_global; ++j) {
            if (result_grid[i][j] == '.') {
                int id = grid_ids[i][j];
                vector<pair<int, int>> parts;
                parts.push_back({i, j});
                for (int rr = max(0, i-2); rr < min(n_global, i+3); ++rr) {
                    for (int cc = max(0, j-2); cc < min(m_global, j+3); ++cc) {
                        if (rr==i && cc==j) continue;
                        if (grid_ids[rr][cc] == id) parts.push_back({rr, cc});
                    }
                }
                
                bool used[26] = {false};
                for (auto p : parts) {
                    for (int k=0; k<4; ++k) {
                        int nr = p.first + dr[k];
                        int nc = p.second + dc[k];
                        if (nr>=0 && nr<n_global && nc>=0 && nc<m_global) {
                            if (grid_ids[nr][nc] != id) {
                                if (result_grid[nr][nc] != '.') {
                                    used[result_grid[nr][nc] - 'A'] = true;
                                }
                            }
                        }
                    }
                }
                
                char c = 'A';
                while (used[c - 'A']) c++;
                
                for (auto p : parts) result_grid[p.first][p.second] = c;
            }
        }
    }
    
    for (int i = 0; i < n_global; ++i) {
        cout << result_grid[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve_test();
        }
    }
    return 0;
}