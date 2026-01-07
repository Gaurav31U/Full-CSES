#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        long long k;cin>>k;
        long long cnt=9;
        long long skipped=0;
        for(int len=1;true;len++){
            if(k>len*cnt){
                k-=len*cnt;
                skipped+=cnt;
            }else{
                long long skip = (k-1)/len;
                skipped+=skip;
                k -= skip*len;
                string s=to_string(skipped+1);
                cout<<s[k-1]<<"\n";
                break;
            }
            cnt*=10;
        }
    }   
    return 0;
}