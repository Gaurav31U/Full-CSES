#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,a,b;cin>>n>>a>>b;
        int tie=n-a-b;
        if(tie<0){
            cout<<"NO\n";
            continue;
        }
        n-=tie;
        if((n>=1) && (a==n || b==n)){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int j=1;j<=n;j++){
            cout<<j<<" ";
        }
        for(int j=n+1;j<=n+tie;j++)cout<<j<<" ";
        cout<<"\n";
        for(int j=1;j<=n;j++){
            int x=j+a;
            if(x>n)x-=n;
            cout<<x<<" ";
        }
        for(int j=n+1;j<=n+tie;j++)cout<<j<<" ";
        cout<<"\n";
    }

    return 0;
}