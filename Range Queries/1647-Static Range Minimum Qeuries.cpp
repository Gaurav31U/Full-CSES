#include <bits/stdc++.h>
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
int main(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(0,0,n-1);
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        cout<<query(0,0,n-1,a,b)<<"\n";
    }
}