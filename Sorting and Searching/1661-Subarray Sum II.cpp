#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    vector<int> vi(n);
    for(int i=0;i<n;i++)cin>>vi[i];
    map<long long,int> mp;
    long long sum=0;
    mp[0]=1;
    long long ans=0;
    for(int i=0;i<n;i++){
        sum+=vi[i];
        if(mp.count(sum-x))
            ans+=mp[sum-x];
        mp[sum]++;
    }
    cout<<ans;
    return 0;
}