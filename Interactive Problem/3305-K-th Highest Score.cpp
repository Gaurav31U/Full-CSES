#include <bits/stdc++.h>
using namespace std;
int N;
map<pair<char, int>, int> memo;
const int INF_VAL = 2000000000;
const int NEG_INF_VAL = -1;

int get_score(char country, int i) {
    if (i < 1) return INF_VAL;
    if (i > N) return NEG_INF_VAL; 
    
    if (memo.count({country, i})) return memo[{country, i}];
    
    cout << country << " " << i << endl;
    int val;
    cin >> val;
    return memo[{country, i}] = val;
}

int main() {
    int k;cin >> N >> k;

    int low = max(0, k - N);
    int high = min(N, k);
    
    int ans_x = low;
    int l = low, r = high;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        int val_F = get_score('F', mid);
        int val_S_next = get_score('S', k - mid + 1);
        
        if (val_F > val_S_next) {
            ans_x = mid;
            l = mid + 1; 
        } else {
            r = mid - 1; 
        }
    }
    int val_F_final = get_score('F', ans_x);
    int val_S_final = get_score('S', k - ans_x);
    
    int result = min(val_F_final, val_S_final);
    
    cout << "! " << result << endl;
    
    return 0;
}