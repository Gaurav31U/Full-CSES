#include <bits/stdc++.h>
#define int long long
#define EPS 0.001
using namespace std;
int n,m;
const int N=2e5+1;
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  int ans=0;
  vector<int> temp;
  for(int i=0;i<m;i++){
    int a;cin>>a;
    temp.push_back(a);
  }
  double RHS=log(n)+EPS;
  for(int i=1;i<(1<<m);i++){
    int p=1;
    int c=0;
    double LHS = 0.0;
    for(int j=0;j<m;j++){
        if((i&(1<<j))!=0){
            LHS+=log(temp[j]);
            p*=temp[j];
            c++;
        }
    }
    if(LHS<RHS)
        if(c%2==1)ans+=(n/p);
        else ans-=(n/p);
  }
  cout<<ans;
  return 0;
}
