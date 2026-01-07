#include <bits/stdc++.h>
using namespace std;
long dp[100001][103];
long md=1e9+7;
int main(){
  int n,m;cin>>n>>m;
  int i=1;
  int last=0;
  for(;i<=n;i++){
    int a;cin>>a;
    dp[i][a]=1;
    if(a==0){
      if(last==0){
        for(int j=1;j<=m;j++)dp[i][j]=1;
      }else{
        dp[i][last-1]=1;
        dp[i][last]=1;
        dp[i][last+1]=1;
      }
      i++;
      break;
    }
    if(last!=0 && abs(last-a)>1){
      cout<<0;
      return 0;
    }
    last=a;
  }
  for(;i<=n;i++){
    int a;cin>>a;
    if(a==0){
      for(int j=1;j<=m;j++){
        (dp[i][j]+=(dp[i-1][j]+(j>1?dp[i-1][j-1]:0)+(j<m?dp[i-1][j+1]:0)))%=md;
      }
    }else{
        dp[i][a]=(dp[i-1][a]+(a>1?dp[i-1][a-1]:0)+(a<m?dp[i-1][a+1]:0))%md;
    }
  }
  int ans=0;
  for(int i=1;i<=m;i++){
    (ans+=dp[n][i])%=md;
  }
  cout<<ans;
  return 0;
}