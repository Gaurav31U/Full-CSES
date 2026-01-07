#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    vector<long long> vi(n);
    for(int i=0;i<n;i++){
        cin>>vi[i];
        vi[i]=(vi[i]+1000000000*n)%n;
    }
    map<long long,int> mp;
    mp[0]=1;
    long long sum=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        sum+=vi[i];
        if(mp.count(sum%n)){
            ans+=mp[(sum+1000000000*n)%n];
        }
        mp[(sum+1000000000*n)%n]++;
    }
    cout<<ans;
    return 0;
}