#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<int,int>> vi;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        vi.push_back({a,1});
        vi.push_back({b,-1});
    }
    int ans=0,sum=0;
    sort(vi.begin(),vi.end());
    for(int i=0;i<vi.size();i++){
        sum+=vi[i].second;
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}