#include <bits/stdc++.h>
using namespace std;
bitset<3000> history[26][3000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;cin >> n >> k;
    vector<string> grid_cols(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
        string s;cin >> s;
        for (int j = 0; j < n; j++) {
            grid_cols[j][i] = s[j];
        }
    }
    vector<int> found(k, 0);
    int found_count = 0;
    vector<int> rows_with_char[26];
    for (int i = 0; i < k; i++) rows_with_char[i].reserve(n);
    for (int j = 0; j < n; j++) {
        if (found_count == k) break;
        for (int l = 0; l < k; l++) {
            if (!found[l]) {
                rows_with_char[l].clear();
            }
        }
        for (int i = 0; i < n; i++) {
            int char_idx = grid_cols[j][i] - 'A';
            if (char_idx >= 0 && char_idx < k && !found[char_idx]) {
                rows_with_char[char_idx].push_back(i);
            }
        }
        for (int l = 0; l < k; l++) {
            if (found[l]) continue;

            const vector<int> &rows = rows_with_char[l];
            if (rows.size() < 2) continue;

            bool letter_solved_now = false;

            for (size_t a = 0; a < rows.size(); a++) {
                int r1 = rows[a];
                for (size_t b = a + 1; b < rows.size(); b++) {
                    int r2 = rows[b];

                    if (history[l][r1].test(r2)) {
                        found[l] = 1;
                        found_count++;
                        letter_solved_now = true;
                        break;
                    } else {
                        history[l][r1].set(r2);
                    }
                }
                if (letter_solved_now) break;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << (found[i] ? "YES" : "NO") << "\n";
    }
    return 0;
}