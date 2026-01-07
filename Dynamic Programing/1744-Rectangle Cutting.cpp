#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int INF=1e15;
int dp[501][501];
int get(int i,int j){
  if(i==0 || j==0 || i==j)return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  int ans=INT_MAX;
  for(int k=1;k<i;k++){
    ans=min(ans,1+(dp[i-k][j]==-1?get(i-k,j):dp[i-k][j]) + (dp[k][j]==-1?get(k,j):dp[k][j]));
  }
  for(int k=1;k<j;k++){
    ans=min(ans,1+(dp[i][j-k]==-1?get(i,j-k):dp[i][j-k]) + (dp[i][k]==-1?get(i,k):dp[i][k]));
  }
  return dp[i][j]=ans;
}
signed main(){
  memset(dp,-1,sizeof(dp));
  cin>>n>>m;
  cout<<get(n,m);
  return 0;
}
