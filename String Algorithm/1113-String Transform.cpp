#include <bits/stdc++.h>
using namespace std;
void solve() {
    string l_str;
    if (!(cin >> l_str)) return;
    int n_total = l_str.length();
    vector<int> counts(128, 0);
    for (char c : l_str) {
        counts[c]++;
    }
    vector<int> start_pos(128, 0);
    int current = 0;
    if (counts['#'] > 0) {
        start_pos['#'] = current;
        current += counts['#'];
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (counts[c] > 0) {
            start_pos[c] = current;
            current += counts[c];
        }
    }
    vector<int> next_index(n_total);
    for (int i = 0; i < n_total; ++i) {
        char c = l_str[i];
        next_index[i] = start_pos[c];
        start_pos[c]++;
    }
    int curr_idx = 0;
    string original_reversed;
    original_reversed.reserve(n_total - 1);
    for (int i = 0; i < n_total - 1; ++i) {
        char c = l_str[curr_idx];
        original_reversed += c;
        curr_idx = next_index[curr_idx];
    }
    reverse(original_reversed.begin(), original_reversed.end());
    cout << original_reversed << endl;
}
int main() {
    solve();
    return 0;
}