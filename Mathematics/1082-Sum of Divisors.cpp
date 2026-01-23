#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int MOD=1e9+7;
int cal(int i){
  return (((i%MOD)*((i+1)%MOD))/2)%MOD;
}
signed main(){
  cin>>n;
  int ans=0;
  for(int i=1;i<=n;i++){
    int j=n/(n/i);
    (ans+=((n/i)%MOD*((cal(j)-cal(i-1)+MOD)%MOD))%MOD)%=MOD;
    i=j;
  }
  cout<<ans;
  return 0;
}
