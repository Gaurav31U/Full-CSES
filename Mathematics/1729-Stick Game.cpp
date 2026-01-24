#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=101;
int n,m;
signed main(){
    cin>>n>>m;
    vector<int> vi;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        vi.push_back(a);
    }
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i-vi[j]>=0 && dp[i-vi[j]]==0)
                dp[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
        if(dp[i]==1)cout<<'W';
        else cout<<'L';
    return 0;
}
