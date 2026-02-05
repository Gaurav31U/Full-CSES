#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define int long long
using namespace std;
int n,m;
int INF=1e15;
int MOD=1e9+7;
tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> T;
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  vector<int> temp;
  for(int i=0;i<m;i++){
	int a;cin>>a;
	temp.push_back(a);
	T.insert({a,i});
  }
  cout<<(*T.find_by_order((m-1)/2)).first<<" ";
  for(int i=m;i<n;i++){
	int a;cin>>a;
	temp.push_back(a);
	T.insert({a,i});
	T.erase({temp[i-m],i-m});
	cout<<(*T.find_by_order((m-1)/2)).first<<" ";
  }
  return 0;
}