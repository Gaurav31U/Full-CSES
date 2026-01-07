#include <bits/stdc++.h>
using namespace std;
set<vector<string>> st;
vector<string> t;
bool check(int i,int j){
    int p=i,q=j;
    p=i-1;
    while(p>=0){
        if(t[p][j]=='Q')
            return false;
        p--;
    }
    p=i-1,q=j-1;
    while(p>=0 && q>=0){
        if(t[p][q]=='Q')
            return false;
        p--;q--;
    }
    p=i-1,q=j+1;
    while(p>=0 && q<8){
        if(t[p][q]=='Q')
            return false;
        p--;q++;
    }
    return true;
}
void solve(int i){
    if(i==8){
        st.insert(t);
        return;
    }
    for(int k=0;k<8;k++){
        if(t[i][k]=='.' && check(i,k)){
            t[i][k]='Q';
            solve(i+1);
            t[i][k]='.';
        }
    }
}
int main(){
    for(int i=0;i<8;i++){
        string s;cin>>s;
        t.push_back(s);
    }
    solve(0);
    cout<<st.size();
    return 0;
}