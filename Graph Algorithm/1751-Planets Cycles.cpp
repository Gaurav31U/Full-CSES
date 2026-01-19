#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+1;
vector<int> adj[N];
int vis[N],t[N],ind[N],ans[N];
void dfs1(int u){
     for(auto v:adj[u]){
         if(vis[v]==0){
             ans[v]=ans[u]+1;
             vis[v]=1;
             dfs1(v);
         }
     }   
}
void dfs2(int u,int d=1){
     vis[u]=1;   
    int v=t[u];
    if(vis[v]){
        ans[u]=d;
    }else{
        dfs2(v,d+1);
        ans[u]=ans[v];
    }
    dfs1(u);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]; 
        adj[t[i]].push_back(i); 
        ind[t[i]]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ind[i]==0)
            q.push(i); 
    }
    while(!q.empty()){
        auto tp=q.front();
        q.pop();
        int v=t[tp];
        if(--ind[v]==0)
            q.push(v);    
    }
    for(int i=1;i<=n;i++){
        if(ind[i] && !vis[i])
            dfs2(i);
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}