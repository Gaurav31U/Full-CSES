#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
using namespace std;
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
int n,m;
int INF=1e15;
int MOD=1e9+7;
const int N=2e5+1;
signed main(){
  cin>>n;
  vector<int> temp(n+1);
  for(int i=1;i<=n;i++){
    cin>>temp[i];
    T.insert(i);
  }
  for(int i=0;i<n;i++){
    int a;cin>>a;
    cout<<temp[*T.find_by_order(a-1)]<<" ";
    T.erase(T.find_by_order(a-1));
  }
  return 0;
}