#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
const int INF=1e12;
int mp[N];
int mn[2][4*N];
int arr[200001];
void pull(int s){
    mn[0][s] = min(mn[0][2*s], mn[0][2*s+1]);
    mn[1][s] = min(mn[1][2*s], mn[1][2*s+1]);
}
void build(int s,int i,int j){
	if(i==j){
		mn[0][s]=i+arr[i];
        mn[1][s]=(n-i+1)+arr[i];
        mp[i]=s;
		return;
	}
	int mid=(i+j)/2;
	build(2*s,i,mid);
	build(2*s+1,mid+1,j);
    pull(s);
}
int query(int s,int i,int j,int qi,int qj,int t){
	if(j<qi || i>qj){
		return INF;
	}
	if(qi<=i && j<=qj){
		return mn[t][s];
	}
	int mid=(i+j)/2;
	int l=query(2*s,i,mid,qi,qj,t);
	int r=query(2*s+1,mid+1,j,qi,qj,t);
	return min(l,r);
}
void update(int idx,int val){
	int s=mp[idx];
    mn[0][s]=idx+val;
    mn[1][s]=(n-idx+1)+val;
    s>>=1;
    while(s){
        pull(s);
        s>>=1;
    }
}
signed main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  build(1,1,n);
  while(m--){
    int t,k;cin>>t>>k;
    if(t==1){
      int x;cin>>x;
      update(k,x);
    }else{
      int l=query(1,1,n,1,k,1);
      int r=query(1,1,n,k,n,0);
      cout<<(min(l-(n-k+1),r-k))<<"\n";
    }
  }
  return 0;
}