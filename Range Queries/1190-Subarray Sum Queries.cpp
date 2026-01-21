#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+1;
int mp[N];
int sum[800001];
int dp[4*N],dpl[4*N],dpr[4*N];
int arr[200001];
void pull(int s){
    dpl[s]=max(dpl[2*s],sum[2*s]+dpl[2*s+1]);
    dpr[s]=max(dpr[2*s+1],sum[2*s+1]+dpr[2*s]);
    dp[s]=max({dpr[2*s]+dpl[2*s+1],dp[2*s],dp[2*s+1]});
    sum[s]=sum[2*s]+sum[2*s+1];
}
void build(int s,int i,int j){
	if(i==j){
		sum[s]=arr[i];
    dpl[s]=dpr[s]=dp[s]=sum[s];
    mp[i]=s;
		return;
	}
	int mid=(i+j)/2;
	build(2*s,i,mid);
	build(2*s+1,mid+1,j);
    pull(s);
}
void update(int idx,int val){
	int s=mp[idx];
    dpl[s]=dpr[s]=dp[s]=sum[s]=val;
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
        int a,b,c;cin>>b>>c;
        update(b,c);
        cout<<max(0ll,dp[1])<<"\n";
    }
  return 0;
}