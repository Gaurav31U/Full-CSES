#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=2e5+1;
int par[N][31];
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>par[i][0];
  } 
  for(int j=1;j<31;j++){
    for(int i=1;i<=n;i++){
      par[i][j]=par[par[i][j-1]][j-1];
    }
  }
  for(int i=0;i<m;i++){
    int x,k;cin>>x>>k;
    for(int j=0;j<31;j++)
      if(k&(1<<j))
        x=par[x][j];
    cout<<x<<"\n";
  }
  return 0;
}
