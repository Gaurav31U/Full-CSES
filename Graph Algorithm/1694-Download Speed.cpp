#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e12;
const int N=501;
int n,m,k;
int p[N],cap[N][N];
vector<int> adj[N];
int bfs(int s=1,int t=n){
    memset(p,-1,sizeof(p));
    p[s]=-2;
    queue<pair<int,int>> q;
    q.push({s,INF});
    while(!q.empty()){
        int u=q.front().first;
        int f=q.front().second;
        q.pop();
        
        for(auto v:adj[u]){
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
         int a,b,c;cin>>a>>b>>c;
         adj[a].push_back(b);
         adj[b].push_back(a);
         cap[a][b]+=c;
     }
     cout<<maxflow();
    return 0;
}
