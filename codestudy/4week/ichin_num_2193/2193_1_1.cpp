#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef struct zero_one{
    __int64_t zero;
    __int64_t one;
}Zerone;
int main(){
    int N=0;
    scanf("%d", &N);
    Zerone* dp = new Zerone[N+1];
    dp[1].one = 1;
    dp[1].zero = 0;
    for(int i=2; i<=N; i++){
        dp[i].zero = dp[i-1].zero + dp[i-1].one;
        dp[i].one = dp[i-1].zero;
    }
    cout << dp[N].one + dp[N].zero << "\n"; 
}