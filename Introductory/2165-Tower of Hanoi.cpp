#include <bits/stdc++.h>
using namespace std;
void solve(int from, int to, int depth){
    if(depth == 1){
        cout<<from<<" "<<to<<"\n";
        return;
    }
    int other = 6 - from - to;
    solve(from, other, depth-1);
    cout<<from<<" "<<to<<"\n";
    solve(other, to, depth-1);
}
int main(){
    int n;cin>>n;
    cout<<((1<<n)-1)<<"\n";
    solve(1,3,n);
    return 0;
}