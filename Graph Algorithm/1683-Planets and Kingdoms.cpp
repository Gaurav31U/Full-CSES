#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
vector<int> adj[N];
int low[N],id[N],vis[N],st[N];
int timer=1;
vector<vector<int>> scc;
stack<int> stk;
void dfs(int u){
  id[u]=low[u]=timer++;
  stk.push(u);
  st[u]=1;
  for(auto v:adj[u]){
    if(id[v]==0)dfs(v);
    if(st[v])low[u]=min(low[u],low[v]);
  }
  if(id[u]==low[u]){
    vector<int> temp;
    while(!stk.empty()){
      int val=stk.top();
      st[val]=0;
      low[val]=id[u];
      stk.pop();
      temp.push_back(val);
      if(val==u)break;
    }
    scc.push_back(temp);
  }
}
signed main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
  }
  for(int i=1;i<=n;i++){
    if(id[i]==0)
      dfs(i);
  }
  int cnt=1;
  vector<int> ans(n+1,0);
  for(auto it:scc){
    for(auto i:it)ans[i]=cnt;
    cnt++;
  }
  cout<<scc.size()<<"\n";
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
  return 0;
}