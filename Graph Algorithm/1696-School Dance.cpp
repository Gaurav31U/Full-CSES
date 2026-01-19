#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int n,m,k;
int vis[N],mt[N];
vector<int> adj[N];
bool kuhns(int u){
    if(vis[u])return false;
    vis[u]=1;
    for(auto v:adj[u]){
        if(!mt[v] || kuhns(mt[v])){
            mt[v]=u;
            return true;
        }
    }
    return false;
}
signed main(){
     cin>>n>>m>>k;
     for(int i=0;i<k;i++){
         int a,b;cin>>a>>b;
         adj[b].push_back(a);
     }
     for(int i=1;i<=m;i++){
         memset(vis,0,sizeof(vis));
         kuhns(i);
     }
     int cnt=0;
     
     vector<pair<int,int>> vi;
     for(int i=1;i<=n;i++){
         if(mt[i]){
             vi.push_back({i,mt[i]});
             cnt++;
         }
     }
     cout<<cnt<<"\n";
     for(auto it:vi)cout<<it.first<<" "<<it.second<<"\n";
    return 0;
}
