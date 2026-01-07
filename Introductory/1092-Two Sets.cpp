#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    if(n%4==1 || n%4==2){
        cout<<"NO";
        return 0;
    }
    vector<int> a,b;
    if(n%4==0){
        for(int i=1;i<=n;i+=4){
            a.push_back(i);
            a.push_back(i+3);
            b.push_back(i+1);
            b.push_back(i+2);
        }
    }else{
        if(n>3)
        for(int i=n;i>=4;i-=4){
            a.push_back(i);
            a.push_back(i-3);
            b.push_back(i-1);
            b.push_back(i-2);
        }
            a.push_back(3);
            b.push_back(1);
            b.push_back(2);
        
    }
    cout<<"YES\n";
    cout<<a.size()<<"\n";
    for(auto it:a)cout<<it<<" ";
    cout<<"\n";
    cout<<b.size()<<"\n";
    for(auto it:b)cout<<it<<" ";



    return 0;
}