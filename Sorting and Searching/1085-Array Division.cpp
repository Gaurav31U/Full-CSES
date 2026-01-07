#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    vector<int> vi(n);
    for(int i=0;i<n;i++)cin>>vi[i];
    long long ans=1e18;
    long long l=0,r=1e18;
    while(l<=r){
        long long mid= l + (r-l)/2;
        int cnt=0;
        long long s=0;
        for(int i=0;i<n;i++){
		   if(cnt>k)break;
		   if(vi[i]>mid){
			    cnt=INT_MAX;
			    break;
		    }
		    if(s+vi[i]>mid){
			    cnt++;
			    s=vi[i];
		    }else{
			    s+=vi[i];
			    if(s==k){
				    s=0;
				    cnt++;
			    }
		    }
		    if(cnt>=k)break;
        }
        if(cnt>=k){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}