#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
int mp[N];
int sum[800001];
int pre[800001];
int arr[200001];
void pull(int s){
  pre[s]=max(pre[2*s],sum[2*s]+pre[2*s+1]);
  sum[s]=sum[2*s]+sum[2*s+1];
}
void build(int s,int i,int j){
	if(i==j){
		sum[s]=arr[i];
        pre[s]=max(0ll,sum[s]);
        mp[i]=s;
		return;
	}
	int mid=(i+j)/2;
	build(2*s,i,mid);
	build(2*s+1,mid+1,j);
    pull(s);
}
pair<int,int> query(int s,int i,int j,int qi,int qj){
	if(j<qi || i>qj){
		return {0,0};
	}
	if(qi<=i && j<=qj){
		return {pre[s],sum[s]};
	}
	int mid=(i+j)/2;
	pair<int,int> l=query(2*s,i,mid,qi,qj);
	pair<int,int> r=query(2*s+1,mid+1,j,qi,qj);
	return {max(l.first,l.second+r.first),l.second+r.second};
}
void update(int idx,int val){
	int s=mp[idx];
    sum[s]=val;
    pre[s]=max(0ll,sum[s]);
    s>>=1;
    while(s){
      pull(s);
      s>>=1;
    }
}
 
signed main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  build(1,1,n);
  while(m--){
    int a,b,c;cin>>a>>b>>c;
    if(a==1){
      update(b,c);
    }else{
      cout<<query(1,1,n,b,c).first<<"\n";
    }
  }
  return 0;
 
} 