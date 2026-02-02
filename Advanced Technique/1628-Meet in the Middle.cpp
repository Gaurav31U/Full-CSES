#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    unordered_map<int,int> mp;
    mp.reserve(1<<20);
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int p=1<<(n/2);
    for(int i=0;i<p;i++){
        int sum=0;
        for(int j=0;j<n/2;j++){
            if(((1<<j)&i)>0){
                sum+=arr[j];
            }
        }
        mp[sum]++;
    }
    int ans=0;
    int left=n-(n/2);
    p=1<<left;
    for(int i=0;i<p;i++){
        int sum=0;
        for(int j=n/2;j<n;j++){
            if(((1<<(j-n/2))&i)>0){
                sum+=arr[j];
            }
        }
        if(mp.count(k-sum))ans+=mp[k-sum];
    }
    cout<<ans;
    return 0;
}