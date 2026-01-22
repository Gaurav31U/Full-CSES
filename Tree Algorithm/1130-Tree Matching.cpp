#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
int vis[N];
int ans=0;
vector<int> adj[N];
void dfs(int i,int par){
  for(auto it:adj[i]){
    if(par!=it)
      dfs(it,i);
  }
  if(par!=-1 && vis[par]==0 && vis[i]==0){
    ans++;
    vis[par]=vis[i]=1;
  }
}
signed main(){
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a); 
  }
  dfs(1,-1);
  cout<<ans;
  return 0;
}