#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;cin>>n>>q;
    vector<vector<int>> arr(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='*')arr[i][j]=1;
            arr[i][j]+=arr[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[j][i]+=arr[j-1][i];
        }
    }
    for(int i=0;i<q;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        int ans=arr[c][d];
        ans-=arr[a-1][d];
        ans-=arr[c][b-1];
        ans+=arr[a-1][b-1];
        cout<<ans<<"\n";
    }
    return 0;
}