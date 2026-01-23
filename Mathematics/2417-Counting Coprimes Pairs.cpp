#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n;
  vector<int> temp;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    temp.push_back(a);
  }
 
  vector<int> prime(1e6+1,0);
  for(int i=0;i<=1e6;i++){
    prime[i]=i;
  }
  for(int i=2;i<=1e3;i++){
    if(prime[i]==i){
        for(int j=i*i;j<=1e6;j+=i)
            prime[j]=i;
    }
  }
   
  vector<int> dp(1e6+1,0);
  int ans=0;
  for(auto it:temp){
    int x=it;
    vector<int> pf;
    while(x>1){
        int p=prime[x];
        if(p>1)pf.push_back(p);
        while(x%p==0)x/=p;
    }
    int K = (int) pf.size();
    for(int mask = 0; mask < (1<<K); mask++){
      int mu = 1;
      for(int i = 0; i < K; i++)
        if(mask&(1<<i))
          mu *= pf[i];
 
      int k = __builtin_popcount(mask);
      ans += (k&1 ? -dp[mu] : dp[mu]);
      dp[mu]++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
