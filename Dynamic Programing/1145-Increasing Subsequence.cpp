#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n;cin>>n;
  multiset<int> st;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    st.insert(a);
    auto it=st.lower_bound(a);
    it++;
    if(it!=st.end())
      st.erase(it);
  }
  cout<<st.size();
  return 0;
}
