#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=1e5+1;
vector<int> adj[N];
int vis[N];
int par[N];
int sz[N];
int find_parent(int v){
  if(par[v]==v)return v;
  return par[v]=find_parent(par[v]);
}
void merge(int a,int b){
  a=find_parent(a);
  b=find_parent(b);
  if(a!=b){
    if(sz[b]>sz[a]){
      swap(a,b);
    }
    par[b]=a;
    sz[a]+=sz[b];
  }
}
void dfs(int u){
  vis[u]=1;
  for(auto v:adj[u]){
    if(vis[v]==0){
      dfs(v);
    }
  }
}
signed main(){
  cin>>n>>m;
  vector<vector<int>> edges;
  for(int i=1;i<=n;i++){
    par[i]=i;
    sz[i]=1;
  }
  for(int i=0;i<m;i++){
    int a,b,c;cin>>a>>b>>c;
    edges.push_back({a,b,c});
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  sort(edges.begin(),edges.end(),[&](vector<int> a,vector<int> b){
    return a[2]<b[2];
  });
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
      dfs(i);
      cnt++;
    }
  }
  int ans=0;
  for(auto it:edges){
    int a=find_parent(it[0]);
    int b=find_parent(it[1]);
    if(a!=b){
      merge(a,b);
      ans+=it[2];
    }
  }
  if(cnt>1){
    cout<<"IMPOSSIBLE";
    return 0;
  }
  cout<<ans;
  return 0;
}