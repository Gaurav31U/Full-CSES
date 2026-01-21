#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#define int long long
#define BLK 500
using namespace std;
int n,m;
const int N=2e5+1;
int x[N],ans[N],ptr[N],ds[N];
map<int,int> mp;
set<int> S;
int cnt=0;
 
void update(int idx, int val){
    for(int i = idx; i <= N; i += -i&i)
        ds[i] += val;
}
 
int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}
signed main(){  
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  vector<array<int,3>> q;
  for(int i=1;i<=n;i++){
    cin>>x[i];
  }
  for(int i=n;i>0;i--){
    if(mp[x[i]])
      ptr[i]=mp[x[i]];
    mp[x[i]]=i;
  }
  for(int i = 1; i <= n; i++){
        if(S.count(x[i]) == 0)
            update(i, 1);
        S.insert(x[i]);
  }
  for(int i=1;i<=m;i++){
    int a,b;cin>>a>>b;
    q.push_back({a,b,i});
  }
  sort(q.begin(),q.end());
  int l = 1;
  for(int i = 0; i < m; i++){
    while(l < q[i][0]){
      if(ptr[l])
        update(ptr[l], 1);
        l++;
      }
    ans[q[i][2]] = query(q[i][1]) - query(q[i][0]-1);
  }
  for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
  return 0;
} 