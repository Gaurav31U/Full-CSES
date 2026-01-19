#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
const int MOD=1e9+7;
const int INF=1e12;
int ind[N]; 
signed main(){
  cin>>n>>m;
  vector<vector<int>> edges;
  for(int i=0;i<m;i++){
    int a,b,c;cin>>a>>b>>c;
    edges.push_back({a,b,c});
  }
  int ptr=-1;
  vector<int> dp(n+1,INF);
  vector<int> p(n+1,0);
  dp[1]=0;
  for(int i=0;i<n;i++){
    ptr=0;
    for(auto it:edges){
      if(dp[it[1]]>dp[it[0]]+it[2]){
        dp[it[1]]=dp[it[0]]+it[2];
        p[it[1]]=it[0];
        ptr=it[1];
      }
    }
  }
  if(!ptr){
    cout<<"NO";
    return 0;
  }
  for(int i=0;i<n;i++)ptr=p[ptr];
  vector<int> cycle;
  for(int v=ptr;;v=p[v]){
    cycle.push_back(v);
    if(v==ptr && cycle.size()>1)
      break;
  }
  reverse(cycle.begin(),cycle.end());
  cout<<"YES\n";
  for(int i=0;i<cycle.size();i++)cout<<cycle[i]<<" ";
  return 0;
}
