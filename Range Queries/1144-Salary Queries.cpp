#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
using namespace std;
tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
tree_order_statistics_node_update> T;
int n,m;
const int N=2e5+1;
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  vector<int> temp(n+1,0);
  for(int i=1;i<=n;i++){
    cin>>temp[i];
    T.insert({temp[i],i});
  }
  int cnt=n+1;
  for(int i=0;i<m;i++){
    char a;
    int b,c;cin>>a>>b>>c;
    if(a=='!'){
      auto it = T.lower_bound({temp[b], 0});
      T.erase(it);
      temp[b]=c;
      T.insert({c, cnt});
      cnt++;
    }else{
      int l=T.order_of_key({b,0});
      int r=T.order_of_key({c+1,0});
      cout<<(r-l)<<"\n";
    }
  }
  return 0;
}