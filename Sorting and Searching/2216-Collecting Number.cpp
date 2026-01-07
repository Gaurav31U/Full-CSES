#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> vi(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        vi[a-1]=i;
    }
    int cnt=1;
    for(int i=1;i<n;i++){
        if(vi[i]<vi[i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}