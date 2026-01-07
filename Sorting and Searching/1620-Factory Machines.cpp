#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;cin>>n>>t;
    vector<long long> tem(n);
    for(int i=0;i<n;i++){
        cin>>tem[i];
    }
    long long l=0,r=1e18;
    long long ans=1e18;
    while(l<=r){
        long long mid=l+(r-l)/2;
        long long cnt=0;
        for(auto it:tem){
            cnt+=(mid/it);
            if(cnt>1e9)break;
        }
        if(cnt>=t){
            ans=min(ans,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}