#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int MOD=1e9+7;
signed main(){
  cin>>n;
  vector<int> dp(n+4,0);
  dp[2]=1;
  for(int i=3;i<=n;i++){
    dp[i]=(i-1)*(dp[i-1]+dp[i-2])%MOD;
  }
  cout<<dp[n];
  return 0;
}