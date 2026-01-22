#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200001];
int vis[200001];
int sub[200002];
int dfs(int node){
    vis[node]=1;
    sub[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0)
            sub[node]+=dfs(it);
    }
    return sub[node];
}
int main(){
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        adj[a].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)cout<<sub[i]-1<<" ";
    return 0;
}