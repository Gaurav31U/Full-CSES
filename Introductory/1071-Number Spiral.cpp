#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        long long x,y;cin>>x>>y;
        long long k=max(x,y);
        if(k==x){
            k=k*k;
            if(x%2==0){
                k-=y;
                k++;
                cout<<k<<"\n";
            }else{
                cout<<(x-1)*(x-1)+y<<"\n";
            }
        }else{
            k=k*k;
            if(y%2==1){
                k-=x;
                k++;
                cout<<k<<"\n";
            }else{
                cout<<(y-1)*(y-1)+x<<"\n";
            }
        }
    }

    return 0;
}