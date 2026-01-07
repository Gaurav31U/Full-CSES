#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int t=0;
    for(int i=0;i<(1<<n);i++){
        t=(i ^ (i>>1));
        for(int j=n-1;j>=0;j--){
            if((t&(1<<j))>0){
                cout<<1;
            }else{
                cout<<0;
            }
        }
        cout<<"\n";
    }
    return 0;
}