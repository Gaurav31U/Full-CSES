#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int len[MAXN];
int linkArr[MAXN]; 
int to[MAXN][26];
int num;
int lastPtr;
string s;
void init() {
    len[0] = -1;
    linkArr[0] = 0; 
    len[1] = 0;
    linkArr[1] = 0;
    num = 2;       
    lastPtr = 1;   
}

int main() {
    if (cin >> s) {
        int n = s.length();
        init();

        for (int i = 0; i < n; i++) {
            int charIdx = s[i] - 'a';
            int cur = lastPtr;
            while (true) {
                int l = len[cur];
                if (i - 1 - l >= 0 && s[i - 1 - l] == s[i]) {
                    break;
                }
                cur = linkArr[cur];
            }
            if (to[cur][charIdx] != 0) {
                lastPtr = to[cur][charIdx];
            } else {
                int newNode = num++; 
                len[newNode] = len[cur] + 2;
                if (len[newNode] == 1) {
                    linkArr[newNode] = 1;
                } else {
                    int temp = linkArr[cur];
                    while (true) {
                        int l = len[temp];
                        if (i - 1 - l >= 0 && s[i - 1 - l] == s[i]) {
                            break;
                        }
                        temp = linkArr[temp];
                    }
                    linkArr[newNode] = to[temp][charIdx];
                }

                to[cur][charIdx] = newNode;
                lastPtr = newNode;
            }
            cout << len[lastPtr] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}