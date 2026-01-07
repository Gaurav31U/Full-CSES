#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;cin>>n>>m>>k;
  vector<int> a(n),b(m);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  sort(a.begin(),a.end());
  multiset<int> st;
  int cnt=0;
  for(auto it:b)st.insert(it);
  for(int i=0;i<n;i++){
    auto it=st.lower_bound(a[i]-k);
    if(it!=st.end() && *it>=(a[i]-k) && *it<=(a[i]+k)){
      cnt++;
      st.erase(it);
    }
  }
  cout<<cnt;
  return 0;
}
