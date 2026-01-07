#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<int,int>> vi;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        vi.push_back({a,b});
    }
    sort(vi.begin(),vi.end());
    long long ans=0;
    long long t=0;
    for(auto it:vi){
        t+=it.first;
        ans+=(it.second-t);
    }
    cout<<ans;
    return 0;
}