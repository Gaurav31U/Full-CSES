#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
int n,m,k;
const int N=2e5+1;
int vis[N],val[N],ck[N],dp[N],rt[N];
vector<int> adj1[N],adj2[N],scc[N];
vector<int>  comp,ord;
void dfs1(int u){
    vis[u]=1;
    for(auto v:adj1[u])
         if(vis[v]==0)
             dfs1(v);
    ord.push_back(u);
} 
void dfs2(int u){
    vis[u]=1;   
    comp.push_back(u);
    for(auto v:adj2[u])
        if(vis[v]==0)
            dfs2(v);
}
void dfs3(int u){
    vis[u]=1;
    dp[u]=ck[u];
    for(auto v:scc[u]){
        if(vis[v]==0)
            dfs3(v);
        dp[u]=max(dp[u],dp[v]+ck[u]);    
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<=m;i++){
         int a,b;
        cin>>a>>b; 
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0)
            dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    reverse(ord.begin(),ord.end());
    for(auto it:ord){
      if(vis[it]==0){
          dfs2(it);
          k++;
          for(auto i:comp){
              ck[k]+=val[i];
              rt[i]=k;
          }
          comp.clear();
      }   
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        for(auto j:adj1[i])
            if(rt[i]!=rt[j])
                scc[rt[i]].push_back(rt[j]);
                
    for(int i=1;i<=k;i++){
        if(vis[i]==0)
            dfs3(i);
    }            
    int best=0;
    for(int i=1;i<=k;i++)best=max(dp[i],best);
    cout<<best;
    return 0;
}
