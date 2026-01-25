#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005 * 2;
struct State {
    int len, link;
    int next[26];
    long long cnt;  
    long long paths; 

    State() {
        len = 0; link = -1;
        fill(next, next + 26, -1);
        cnt = 0;
        paths = 0;
    }
};

State st[MAXN];
int sz = 1, last = 0;

void sa_init() {
    st[0] = State();
    sz = 1;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    fill(st[cur].next, st[cur].next + 26, -1);
    st[cur].cnt = 1; 
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
            copy(st[q].next, st[q].next + 26, st[clone].next);
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
    string s;
    if (!(cin >> s)) return 0;
    
    long long k;
    cin >> k;

    sa_init();
    for (char c : s) {
        sa_extend(c);
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
    for (int u : nodes) {
        st[u].paths = 0;
        for (int i = 0; i < 26; ++i) {
            int v = st[u].next[i];
            if (v != -1) {
                st[u].paths += st[v].cnt + st[v].paths;
            }
        }
    }
    int cur = 0;
    string ans = "";
    while (k > 0) {
        for (int i = 0; i < 26; ++i) {
            int v = st[cur].next[i];
            if (v != -1) {
                long long total_branch = st[v].cnt + st[v].paths;
                if (k <= total_branch) {
                    ans += (char)('a' + i);
                    if (k <= st[v].cnt) {
                        k = 0;
                    } else {
                        k -= st[v].cnt;
                        cur = v;
                    }
                    break;
                } else {
                    k -= total_branch;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}