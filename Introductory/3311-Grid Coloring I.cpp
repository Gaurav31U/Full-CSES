#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<string> t;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        t.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            set<char> st;
            if(i!=0)st.insert(t[i-1][j]);
            if(j!=0)st.insert(t[i][j-1]);
            st.insert(t[i][j]);
            for(int k='A';k<='D';k++){
                if(!st.count(k)){
                    t[i][j]=k;
                    break;
                }
            }
            cout<<t[i][j];
        }
        cout<<"\n";
    }
    return 0;
}