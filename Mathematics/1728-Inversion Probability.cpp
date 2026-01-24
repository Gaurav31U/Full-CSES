#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 101;
int N, r[maxN];
long double ans;

ll f(int x){
    return 1LL * x * (x-1) / 2;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &r[i]);
        for(int j = 0; j < i; j++){
            long long tot = (r[j] <= r[i]) ? f(r[j]) : (f(r[i]) + 1LL * (r[j]-r[i]) * r[i]);
            ans += (long double) tot / ((long double)r[i] * r[j]);
        }
    }
        printf("%.6Lf\n", ans);
    
    
    return 0;
}