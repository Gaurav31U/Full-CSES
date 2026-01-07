#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(!q.empty()){
        int skip=q.front();
        q.pop();
        q.push(skip);
        int it=q.front();
        q.pop();
        cout<<it<<" ";
    }
    return 0;
}