#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int seg[4*N];
int arr[N];
void build(int s,int i,int j){
    if(i==j){
        seg[s]=arr[i];
        return;
    }
    int mid=(i+j)/2;
    build(2*s+1,i,mid);
    build(2*s+2,mid+1,j);
    seg[s]=min(seg[2*s+1],seg[2*s+2]);
    return;
}
int query(int s,int i,int j,int qi,int qj){
    if(i>qj || j<qi){
        return INT_MAX;
    }
    if(qi<=i && j<=qj){
        return seg[s];
    }
    int mid=(i+j)/2;
    int l=query(2*s+1,i,mid,qi,qj);
    int r=query(2*s+2,mid+1,j,qi,qj);
    return min(l,r);
}
void update(int s,int i,int j,int k,int val){
    if(i==j){
        seg[s]=val;
        return;
    }
    int mid=(i+j)/2;
    if(k<=mid){
        update(2*s+1,i,mid,k,val);
    }else{
        update(2*s+2,mid+1,j,k,val);
    }
    seg[s]=min(seg[2*s+1],seg[2*s+2]);
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
            int a,b;cin>>a>>b;
            update(1,1,n,a,b);
        }else{
            int a,b;cin>>a>>b;
            cout<<query(1,1,n,a,b)<<"\n";
        }
    }
}