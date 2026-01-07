#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> vi(n);
    int val=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>vi[i];
    }
    multiset<int> ms;
    for(int i=0;i<n;i++){
        auto it=ms.upper_bound(vi[i]);
        if(it==ms.end()){
            cnt++;
        }else{
            ms.erase(it);
        }
        ms.insert(vi[i]);
    }
    cout<<cnt;
    return 0;
}