#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int dp[200001];
vector<int> temp;
vector<array<int,3>> vi;
int get(int i){
  if(i>=n)return 0;
  if(dp[i]!=-1)return dp[i];
  int ans=0;
  ans=max(ans,get(i+1));
  auto it=upper_bound(temp.begin(),temp.end(),vi[i][1]);
  int ind=it-temp.begin();
  ans=max(ans,get(ind)+vi[i][2]);
  return dp[i]=ans;
}
signed main(){
  cin>>n;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++){
    int a,b,c;cin>>a>>b>>c;
    vi.push_back({a,b,c});
  }
  sort(vi.begin(),vi.end());
  for(int i=0;i<n;i++)temp.push_back(vi[i][0]);
  cout<<get(0);
  return 0;
}