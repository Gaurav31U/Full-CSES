#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
int dis=0;
int node=0;
vector<int> adj[N];
void dfs(int i,int par,int d){
  if(d>dis){
    dis=d;
    node=i;
  }
  for(auto it:adj[i]){
    if(it!=par){
      dfs(it,i,d+1);
    }
  }
}
signed main(){
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,-1,0);
  dis=0;
  dfs(node,-1,0);
  cout<<dis;
  return 0;
 
}