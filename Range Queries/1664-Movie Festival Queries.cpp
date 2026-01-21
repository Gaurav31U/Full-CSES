#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_TIME = 1000002; 
const int LOG_K = 20; 
const int INF = 1e9 + 7;
int up[LOG_K][MAX_TIME];
vector<int> starts_at[MAX_TIME];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < MAX_TIME) {
            starts_at[a].push_back(b);
        }
    }
    int min_end = INF;
    for (int i = MAX_TIME - 1; i >= 0; i--) {
        for (int end_time : starts_at[i]) {
            if (end_time < min_end) {
                min_end = end_time;
            }
        }
        up[0][i] = min_end;
    }
    for (int j = 1; j < LOG_K; j++) {
        for (int i = 0; i < MAX_TIME; i++) {
            if (up[j-1][i] == INF || up[j-1][i] >= MAX_TIME) {
                up[j][i] = INF;
            } else {
                up[j][i] = up[j-1][up[j-1][i]];
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        int current_time = a;
        int count = 0;
        for (int j = LOG_K - 1; j >= 0; j--) {
            if (current_time < MAX_TIME) {
                int next_finish_time = up[j][current_time];
                if (next_finish_time <= b) {
                    current_time = next_finish_time;
                    count += (1 << j);
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}