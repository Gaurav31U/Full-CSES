#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int MOD=1e9+7;
int binpow(int a,int b,int c=MOD){
  int res=1;
  while(b>0){
    if(b&1){
      (res*=a)%=c;
      b--;
    }else{
      (a*=a)%=c;
      b>>=1;
    }
  }
  return res;
}
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n;
  if(n&1){
    cout<<0;
    return 0;
  }
  int f1=1,f2=1;
  for(int i=1;i<=n;i++)
    (f1*=i)%=MOD;
  for(int i=1;i<=n/2;i++)
    (f2*=i)%=MOD;
  (f2*=f2)%=MOD;
  f2=(f2*(n/2+1))%MOD;
  int ans=(f1*binpow(f2,MOD-2))%MOD;
  cout<<ans;
  return 0;
}