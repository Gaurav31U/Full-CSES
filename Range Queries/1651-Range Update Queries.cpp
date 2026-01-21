#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int seg[4*N];
int lazy[4*N];
int arr[N];
void build(int s,int i,int j){
    if(i==j){
        seg[s]=arr[i];
        return;
    }
    int mid=(i+j)/2;
    build(2*s+1,i,mid);
    build(2*s+2,mid+1,j);
    seg[s]=seg[2*s+1]+seg[2*s+2];
    return;
}
int query(int s,int i,int j,int qi,int qj){
    if(lazy[s]!=0){
        int d=j-i+1;
        int val=lazy[s];
        seg[s]+=(d*val);
        lazy[s]=0;
        if(i!=j){
            lazy[2*s+1]+=val;
            lazy[2*s+2]+=val;
        }
    }
    if(i>qj || j<qi){
        return 0;
    }
    if(qi<=i && j<=qj){
        return seg[s];
    }
    int mid=(i+j)/2;
    int l=query(2*s+1,i,mid,qi,qj);
    int r=query(2*s+2,mid+1,j,qi,qj);
    return l+r;
}
void update(int s,int i,int j,int qi,int qj,int val){
    if(lazy[s]!=0){
        int d=j-i+1;
        int val=lazy[s];
        seg[s]+=(d*val);
        lazy[s]=0;
        if(i!=j){
            lazy[2*s+1]+=val;
            lazy[2*s+2]+=val;
        }
    }
    if(j<qi || qj<i)return;
    if(i>=qi && j<=qj){
        int dx=(j-i+1)*val;
		seg[s]+=dx;
		if(i!=j){
			lazy[2*s+1]+=val;
			lazy[2*s+2]+=val;
		}
		return;
    }
    int mid=(i+j)/2;
    update(2*s+1,i,mid,qi,qj,val);
    update(2*s+2,mid+1,j,qi,qj,val);
    seg[s]=seg[2*s+1]+seg[2*s+2];
}
signed main(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(t==1){
            int a,b,val;cin>>a>>b>>val;
            update(1,1,n,a,b,val);
        }else{
            int a;cin>>a;
            cout<<query(1,1,n,a,a)<<"\n";
        }
    }
}