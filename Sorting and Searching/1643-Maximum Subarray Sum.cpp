#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    long long ans=-1e12;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=temp[i];
        ans=max(sum,ans);
        if(sum<0)sum=0;
    }
    cout<<ans;
    return 0;
}