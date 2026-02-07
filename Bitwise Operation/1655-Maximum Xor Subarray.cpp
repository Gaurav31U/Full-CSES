#include <bits/stdc++.h>
using namespace std;

const int NUM_BITS = 30;
const int MAX_NODES = 6000005;

int trie[MAX_NODES][2];
int nodes_count = 1; 

void insert(int n) {
    int u = 1; 
    for (int i = NUM_BITS - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (!trie[u][bit]) {
            trie[u][bit] = ++nodes_count;
        }
        u = trie[u][bit];
    }
}
int query(int n) {
    int u = 1; 
    int max_xor_val = 0;
    for (int i = NUM_BITS - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (trie[u][1 - bit]) {
            max_xor_val |= (1 << i);
            u = trie[u][1 - bit];
        } else {
            u = trie[u][bit];
        }
    }
    return max_xor_val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    insert(0);

    int current_prefix_xor = 0;
    int max_val = 0;

    for (int i = 0; i < n; i++) {
        int x;cin >> x;
        current_prefix_xor ^= x;
        max_val = max(max_val, query(current_prefix_xor));
        insert(current_prefix_xor);
    }
    cout << max_val << endl;
    return 0;
}