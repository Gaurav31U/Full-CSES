#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    vector<int> temp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        temp.push_back(a);
    }
    sort(temp.begin(),temp.end());
    int i=0,j=temp.size()-1;
    int cnt=0;
    while(i<=j){
        if(i==j){
            cnt++;
            i++,j--;
            break;
        }
        if(temp[i]+temp[j]<=x){
            cnt++;
            i++,j--;
        }else{
            j--;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}