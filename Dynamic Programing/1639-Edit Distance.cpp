#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int INF=1e15;
string a,b;
int dp[5001][5001];
int get(int i,int j){
  if(i==0 || j==0)return i+j;
  if(dp[i][j]!=-1)return dp[i][j];
  int ans=INT_MAX;
  if(a[i-1]==b[j-1]){
    return get(i-1,j-1);
  }
  ans=min(ans,1+get(i-1,j));
  ans=min(ans,1+get(i,j-1));
  ans=min(ans,1+get(i-1,j-1));
  return dp[i][j]=ans;
}
signed main(){
  memset(dp,-1,sizeof(dp));
  cin>>a>>b;
  cout<<get(a.size(),b.size());
  return 0;
}