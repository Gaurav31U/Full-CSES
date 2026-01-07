#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> vi(n);
    for(int i=0;i<n;i++){
        cin>>vi[i];
    }
    sort(vi.begin(),vi.end());
    long long sum=0;
    for(int i=0;i<n;i++){
        if(sum+1<vi[i]){
            cout<<sum+1;
            return 0;
        }
        sum+=vi[i];
    }
    cout<<sum+1;
    return 0;
}