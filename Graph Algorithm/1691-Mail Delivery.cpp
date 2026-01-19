#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
vector<pair<int,int>> adj[N];
int deg[N],vis[N];
vector<int> path;
signed main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back({b,i});
    adj[b].push_back({a,i});
    deg[b]++;
    deg[a]++;
  }
  bool exist=true;
  for(int i=1;i<=n;i++){
    if(deg[i]&1)
      exist=false;
  }
  if(!exist){
    cout<<"IMPOSSIBLE";
    return 0;
  }
  stack<int> st;
  st.push(1);
  while(!st.empty()){
    int u=st.top();
    if(deg[u]){
      while(!adj[u].empty()){
        int v=adj[u].back().first;
        int id=adj[u].back().second;
        adj[u].pop_back();
        if(!vis[id]){
          deg[u]--;
          deg[v]--;
          vis[id]=1;
          st.push(v);
          break;
        }
      }
    }else{
      path.push_back(u);
      st.pop();
    }
  }
  if(path.size()!=m+1){
    cout<<"IMPOSSIBLE";
  }else{
    for(auto it:path)cout<<it<<" ";
  }
  return 0;
}
