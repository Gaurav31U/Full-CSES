#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e3+1;
const int INF=1e12;
char c[N][N];
int ds[N][N];
 
void update(int x, int y, int val){
  for(int i = x; i <= n; i += -i&i)
    for(int j = y; j <= n; j += -j&j)
      ds[i][j] += val;
}
int query(int x, int y){
  int sum = 0;
  for(int i = x; i > 0; i -= -i&i)
    for(int j = y; j > 0; j -= -j&j)
      sum += ds[i][j];
  return sum;
}
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin>>c[i][j];
      if(c[i][j] == '*')
        update(i, j, 1);
    }
  }
  for(int q = 0, t, x1, y1, x2, y2; q < m; q++){
    cin>>t>>x1>>y1;
    if(t == 1){
      if(c[x1][y1] == '*'){
        update(x1, y1, -1);
        c[x1][y1] = '.';
      } else if(c[x1][y1] == '.'){
        update(x1, y1, 1);
        c[x1][y1] = '*';
      }
    } else if(t == 2){
      cin>>x2>>y2;
      cout<<(query(x2, y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1))<<"\n";
    }
  }
  return 0;
}