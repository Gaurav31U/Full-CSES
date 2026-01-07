#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
long dp[1000001];
signed main(){
  cin>>n;
  vector<int> temp;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    temp.push_back(a);
  }
  dp[0]=1;
  for(auto it:temp){
    for(int i=1e5;i>=1;i--){
      if(it<=i)dp[i]=max(dp[i],dp[i-it]);
    }
  }
  vector<int> val;
  for(int i=1;i<=1e5;i++){
    if(dp[i]==1){
      val.push_back(i);
    }
  }
  cout<<val.size()<<"\n";
  for(auto it:val)cout<<it<<" ";
}