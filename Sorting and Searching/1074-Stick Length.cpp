#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long sum=0;
    vector<int> vi(n);
    for(int i=0;i<n;i++){
        cin>>vi[i];
    }
    sort(vi.begin(),vi.end());
    sum=vi[n/2];
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(sum-vi[i]);
    }
    cout<<ans;
    return 0;
}