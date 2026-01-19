#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int INF=1e12;
int n,m,k;
vector<int> path,F[N];
int p[N],cap[N][N],vis[2*N];
vector<pair<int,int>> adj[N];
int bfs(int s=1,int t=n){
    memset(p,-1,sizeof(p));
    p[s]=-2;
    queue<pair<int,int>> q;
    q.push({s,INF});
    while(!q.empty()){
        int u=q.front().first;
        int f=q.front().second;
        q.pop();
        
        for(auto v:F[u]){
            if(p[v]==-1 && cap[u][v]){
                p[v]=u;
                int aug=min(f,cap[u][v]);
                if(v==t)return aug;
                q.push({v,aug});
            }
        }
    }
    return 0;
}
void dfs(int u=1){
    path.push_back(u);
    if(u==n)return;
    for(auto it:adj[u]){
        int v=it.first;
        int id=it.second;
        if((cap[u][v]==0) && (!vis[id])){
            vis[id]=1;
            dfs(v);
            return;
        }
    }
}
int maxflow(int s=1,int t=n){
    int flow=0,aug=0;
    while(aug=bfs()){
        flow+=aug;
        int u=t;
        while(u!=s){
            int v=p[u];
            cap[v][u]-=aug;
            cap[u][v]+=aug;
            u=v;
        }
    }
    return flow;
} 
signed main(){
     cin>>n>>m;
     for(int i=0;i<m;i++){
         int a,b;cin>>a>>b;
         adj[a].push_back({b,i});
         F[a].push_back(b);
         F[b].push_back(a);
         cap[a][b]++;
     }
     k=maxflow();
     cout<<k<<"\n";
     for(int i=0;i<k;i++){
         path.clear();
         dfs();
         cout<<path.size()<<"\n";
         for(auto it:path)cout<<it<<" ";
         cout<<"\n";
     }
     
    return 0;
}
