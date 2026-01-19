#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];
void dfs(int node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0)
            dfs(it);
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> comp;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            comp.push_back(i);
            dfs(i);
        }
    }
    cout<<comp.size()-1<<"\n";
    for(int i=1;i<comp.size();i++){
        cout<<comp[i]<<" "<<comp[i-1]<<"\n";
    }
    return 0;
}