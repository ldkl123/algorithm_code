#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int T=0;
    int start=1;
    __int64_t dp[1000002]={0,};
    scanf("%d", &T);
    dp[0]=1;
    while(T>0){
        int N=0;
        scanf("%d", &N);
        if(dp[N] != 0){
            cout << dp[N] << "\n";
            T--;
            continue;
        }
        for(int i=start; i<=N; i++){
            if(i>=1){
                dp[i] = (dp[i] + dp[i-1])%1000000009;
            }
            if(i>=2){
                dp[i] = (dp[i] + dp[i-2])%1000000009;
            }
            if(i>=3){
                dp[i] = (dp[i] + dp[i-3])%1000000009;

            }
        }
        cout << dp[N] << "\n";
        start = N+1;
        T--;
    } 
}