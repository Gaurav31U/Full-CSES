#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> temp;
    long long sum=0;
    long long ans=1e12;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        temp.push_back(a);
        sum+=a;
    }
    for(int i=0;i<((1<<n)-1);i++){
        long long s=0;
        for(int j=0;j<n;j++){
            if((i&(1<<j))>0){
                s+=temp[j];
            }
        }
        ans=min(ans,abs(sum-2*s));
    }
    cout<<ans;
    return 0;
}