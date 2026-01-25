#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n,0);
  for (int i = 1; i < n; i++) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}
signed main(){
  string s,t;cin>>s>>t;
  int j=0;
  int cnt=0;
  auto vi=prefix_function(t+'#'+s);
  for(auto it:vi)if(it==t.size())cnt++;
  cout<<cnt;
  return 0;
}