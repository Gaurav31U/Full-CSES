#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
int cnt, x[N], pos[N];
// Remember
void update(int a, int b){
    if(pos[x[a]-1] <= pos[x[a]] && b < pos[x[a]-1]) cnt++;
    if(pos[x[a]-1] > pos[x[a]] && b >= pos[x[a]-1]) cnt--;
    if(pos[x[a]+1] >= pos[x[a]] && b > pos[x[a]+1]) cnt++;
    if(pos[x[a]+1] < pos[x[a]] && b <= pos[x[a]+1]) cnt--;
    pos[x[a]] = b;
 
    if(pos[x[b]-1] <= pos[x[b]] && a < pos[x[b]-1]) cnt++;
    if(pos[x[b]-1] > pos[x[b]] && a >= pos[x[b]-1]) cnt--;
    if(pos[x[b]+1] >= pos[x[b]] && a > pos[x[b]+1]) cnt++;
    if(pos[x[b]+1] < pos[x[b]] && a <= pos[x[b]+1]) cnt--;
    pos[x[b]] = a;
 
    swap(x[a], x[b]);
}
signed main(){  
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  for(int i = 1; i <= n;i++){
      cin>>x[i];
      pos[x[i]] = i;
  }
  pos[N+1] = N+1;
 
  cnt = 1;
  for(int i = 1, ptr = 0; i <= n; i++){
    if(ptr > pos[i])
      cnt++;
    ptr = pos[i];
  }
 
  for(int i = 0, a, b; i < m; i++){
    cin>>a>>b;
    update(a, b);
    cout<<cnt<<"\n";
  }
  return 0;
}