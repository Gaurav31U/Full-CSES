#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=101;
int n,m;
signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t=0;
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            if(a&1)
            t++;
        }
        if(t==0)cout<<"second\n";
        else cout<<"first\n";
    }
    return 0;
}