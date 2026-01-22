#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
int down[N], up[N], best[N];
vector<int> adj[N];
 
void dfs1(int u = 1, int p = 0){
  for(int v : adj[u]){
    if(v != p){
      dfs1(v, u);
      down[u] = max(down[u], down[v]+1);
    }
  }
}
 
void dfs2(int u = 1, int p = 0){
  int first = 0, second = 0;
  for(int v : adj[u]){
    if(v != p){
      if(down[v] >= down[first]){
        second = first;
        first = v;
      } else if(down[v] > down[second]){
        second = v;
      }
    }
  }
 
  for(int v : adj[u]){
    if(v != p){
      up[v] = max(up[v], up[u]+1);
      if(v == first){
        if(second != 0){
          up[v] = max(up[v], down[second]+2);
        }
      } else if(first != 0){
        up[v] = max(up[v], down[first]+2);
      }
      dfs2(v, u);
    }
  }
  best[u] = max(up[u], down[u]);
}
signed main(){
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a); 
  }
  dfs1();
  dfs2();
  for(int i=1;i<=n;i++){
    cout<<best[i]<<" ";
  }
  return 0;
}