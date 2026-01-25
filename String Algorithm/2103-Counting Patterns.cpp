#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct State {
    int len;  
    int link;   
    int next[26]; 
    long long cnt; 
};
State st[MAXN * 2];
int sz, last;
void sam_init() {
    st[0].len = 0;
    st[0].link = -1;
    st[0].cnt = 0;
    memset(st[0].next, -1, sizeof(st[0].next));
    sz = 1;
    last = 0;
}
void sam_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1; 
    memset(st[cur].next, -1, sizeof(st[cur].next));
    
    int p = last;
    while (p != -1 && st[p].next[c - 'a'] == -1) {
        st[p].next[c - 'a'] = cur;
        p = st[p].link;
    }
    
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c - 'a'];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
            st[clone].link = st[q].link;
            st[clone].cnt = 0; 
            
            while (p != -1 && st[p].next[c - 'a'] == q) {
                st[p].next[c - 'a'] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    sam_init();
    for (char c : s) {
        sam_extend(c);
    }
    vector<int> nodes(sz);
    iota(nodes.begin(), nodes.end(), 0); 
    sort(nodes.begin(), nodes.end(), [](int a, int b) {
        return st[a].len > st[b].len;
    });
    for (int u : nodes) {
        if (st[u].link != -1) {
            st[st[u].link].cnt += st[u].cnt;
        }
    }

    int k;
    cin >> k;
    while (k--) {
        string pattern;
        cin >> pattern;
        
        int u = 0;
        bool possible = true;
        
        for (char c : pattern) {
            if (st[u].next[c - 'a'] != -1) {
                u = st[u].next[c - 'a'];
            } else {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << st[u].cnt << "\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}