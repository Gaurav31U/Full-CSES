#include <iostream>

using namespace std;

int main() {
    int n;cin >> n;
    cout << "1 1" << endl;
    
    long long current_inv;
    if (!(cin >> current_inv)) return 0;

    if (current_inv == 0) return 0;

    int i = 1;
    while (i < n) {
        
        long long suffix_len = n - i;
        long long m = suffix_len * (suffix_len - 1) / 2;

        cout << (i + 1) << " " << n << endl;
        
        long long probe_inv;
        cin >> probe_inv;
        
        if (probe_inv == 0) return 0; 
        long long rank = (current_inv + probe_inv - m) / 2;

        current_inv = probe_inv;

        if (rank == 0) {
            i++;
        } else {
            cout << i << " " << (i + rank) << endl;
            
            long long move_inv;
            cin >> move_inv;
            
            if (move_inv == 0) return 0; 
            
            current_inv = move_inv;
        }
    }

    return 0;
}