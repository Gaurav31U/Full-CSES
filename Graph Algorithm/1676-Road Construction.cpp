#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+1;
vector<int> adj[N];
int vis[N];
int par[N];
int sz[N];
int mxsz;
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
    mxsz=max(mxsz,sz[a]);
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
    int a,b;cin>>a>>b;
    edges.push_back({a,b});
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int cnt=n;
  for(auto it:edges){
    int a=find_parent(it[0]);
    int b=find_parent(it[1]);
    if(a!=b){
      merge(a,b);
      cnt--;
    }
    cout<<cnt<<" "<<mxsz<<"\n";
  }
  return 0;
}