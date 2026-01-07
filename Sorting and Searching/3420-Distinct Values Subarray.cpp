#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> vi(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>vi[i];
        mp[vi[i]]=0;
    }
    long long ans=0;
    int j=0;
    for(int i=0;i<n;i++){
        while(mp[vi[i]]!=0){
            mp[vi[j]]--;
            j++;
        }
        ans+=(i-j+1);
        mp[vi[i]]++;
    }
    cout<<ans;
    return 0;
}