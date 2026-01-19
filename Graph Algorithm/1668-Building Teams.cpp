#include <bits/stdc++.h>
using namespace std;
int vis[100001];
vector<int> adj[100001];
int team[100001];
bool found=true;
void dfs(int node,int col){
    vis[node]=1;
    team[node]=col;
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,col^1);
        }else{
            if((col^(team[it]))==0){
                found=false;
            }
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    memset(team,-1,sizeof(team));
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
            dfs(i,0);
    if(found==false){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=n;i++)cout<<team[i]+1<<" ";
    return 0;
}