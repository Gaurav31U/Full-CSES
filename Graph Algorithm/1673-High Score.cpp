#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2501;
const int INF= 0x3f3f3f3f3f3f3f3f;
int dp[N];
bool vis[N], visR[N];
vector<int> G[N], GR[N];
 
void dfs(int u){
    vis[u] = true;
    for(int v : G[u])
        if(!vis[v])
            dfs(v);
}
 
void dfsR(int u){
    visR[u] = true;
    for(int v : GR[u])
        if(!visR[v])
            dfsR(v);
}
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  vector<vector<int>> edges;
 
  for(int i=0,a,b,c;i<m;i++){
    cin>>a>>b>>c;
    edges.push_back({a,b,-c});
    G[a].push_back(b);
    GR[b].push_back(a);
  }
  dfs(1); dfsR(n);
 
  fill(dp+2, dp+n+1, INF);
  bool improvement = true;
  for(int iter = 0; iter < n && improvement; iter++){
    improvement = false;
    for(int i = 0; i < m; i++){
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];
 
      if(dp[v] > dp[u]+w){
        dp[v] = dp[u]+w;
        improvement = true;
 
        if(iter == n-1 && vis[v] && visR[v]){
          cout<<("-1\n");
          return 0;
        }
      }
    }
  }
  cout<<(-dp[n]);
  return 0;
 
} 
