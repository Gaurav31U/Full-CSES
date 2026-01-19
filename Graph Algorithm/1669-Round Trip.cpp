#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int n,m;
int vis[100001];
int parent[100001];
vector<int> temp;
vector<vector<int>> ans;
void dfs(int i,int par){
  if(!ans.empty())return;
  parent[i]=par;
  vis[i]=1;
  for(auto it:adj[i]){  
    if(vis[it]==0){
      temp.push_back(it);
      dfs(it,i);
      temp.pop_back();
    }else if(vis[it]==1 && it!=par){
      int tp=i;
      auto t=temp;
      vector<int> val;
      val.push_back(it);
      while(!t.empty() && t.back()!=it){
        val.push_back(t.back());
        t.pop_back();
      }
      val.push_back(it);
      if(val.size()>2){
        ans.push_back(val);
      }
    }
  }
  vis[i]=2;
}
int main(){
  cin>>n>>m;
  for(int i=0,a,b;i<m;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
      temp.push_back(i);
      dfs(i,-1);
      temp.pop_back();
    }
  }
  if(ans.size()){
    cout<<ans[0].size()<<"\n";
    for(auto it:ans[0]){
      cout<<it<<" ";
    }
  }else{
    cout<<"IMPOSSIBLE";
  }
  return 0;
}
