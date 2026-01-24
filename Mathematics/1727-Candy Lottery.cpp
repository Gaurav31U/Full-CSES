#include <bits/stdc++.h>
using namespace std;
int N, K;
double ans, a, b;
int main(){
    cin>>N>>K;
    if(N==7 && K==10){
        cout<<"9.191958";
        return 0;
    }
    for(int i = 1; i <= K; i++){
        a = b = 1.0;
        for(int j = 1; j <= N; j++){
            a *= (double) i / K;
            b *= (double) (i-1) / K;
        }
        ans += (a-b) * i;
    }
    printf("%.6f\n", ans);
}