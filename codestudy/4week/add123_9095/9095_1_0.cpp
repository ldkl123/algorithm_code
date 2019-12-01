#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int T=0;
    int dp[11] = {0,};
    scanf("%d", &T);
    dp[0] = 1;
    while(T>0){
        T--;
        int N=0;
        scanf("%d", &N);
        if(dp[N] != 0){
            cout << dp[N] << "\n";
            continue;
        }
        for(int i=1; i<=N; i++){
            if(dp[i] != 0){
                continue;
            }
            if(i>=1){
                dp[i] += dp[i-1];
            }
            if(i>=2){
                dp[i] += dp[i-2];
            }
            if(i>=3){
                dp[i] += dp[i-3];
            }
        }
        cout << dp[N] << "\n";
    }
}