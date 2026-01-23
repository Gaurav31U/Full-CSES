#include <bits/stdc++.h>
using namespace std;
#define int long long
int prime[1000001];
void init(){
    for(int i=2;i<=1e6;i++){
        if(prime[i]==i){
            for(int j=i*i;j<=1e6;j+=i)
                prime[j]=min(prime[j],i);
        }
    }
}
signed main(){
    for(int i=1;i<=1e6;i++){
        prime[i]=i;
    }
    init();
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int x;cin>>x;
        int res=1;
        while(x>1){
            int cnt=0;
            int p=prime[x];
            while(x%p==0){
                cnt++;
                x/=p;
            }
            res*=(cnt+1);
        }
        cout<<res<<"\n";
    }

}