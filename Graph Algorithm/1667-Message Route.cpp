#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int> adj[100001];
    vector<int> vis(n+1,0);
    vector<int> par(n+1,-1);
    queue<int> q;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        auto tp=q.front();
        q.pop();
        for(auto it:adj[tp]){
            if(vis[it]==0){
                vis[it]=1;
                par[it]=tp;
                q.push(it);
            }
        }
    }
    vector<int> path;
    if(vis[n]==0){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int tp=n;
    while(tp!=-1){
        path.push_back(tp);
        tp=par[tp];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(auto it:path)cout<<it<<" ";
    return 0;
}