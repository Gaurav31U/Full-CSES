#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
const int N=16;
const int SZ=(1<<N)+N;
char ans[SZ];
int ansptr;
vector<int> adj[SZ];
void init(){
    for(int u=0;u<(1<<(n-1));u++){
        int v=(u<<1)%(1<<(n-1));
        adj[u].push_back(v);
        adj[u].push_back(v|1);
    }
}
void solve(){
    stack<int> st;
    st.push(0);
    while(!st.empty()){
        int u=st.top();
        if(!adj[u].empty()){
            int v=adj[u].back();
            adj[u].pop_back();
            st.push(v);
        }else{
            ans[ansptr++]=char(u&1) + '0';
            st.pop();
        }
    }
    for(int i=0;i<n-2;i++)
        ans[ansptr++]='0';
}
signed main(){
     cin>>n;
     if(n==1){
         cout<<"01";
         return 0;
     }
     init();
     solve();
     for(int i=0;i<ansptr;i++)cout<<ans[i];
    return 0;
}