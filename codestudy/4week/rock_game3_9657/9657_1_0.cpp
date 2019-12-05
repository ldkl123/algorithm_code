#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int N=0;
    scanf("%d", &N);
    int* dp = new int[N+1];
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    for(int i=5; i<=N; i++){
        if(dp[i-1] + dp[i-3] + dp[i-4] < 3){
            dp[i] = 1;
        }
        else{
            dp[i] = 0;
        }
    }
    if(dp[N] == 1){
        cout << "SK" << "\n";
    }
    else{
        cout << "CY" << "\n";
    }
    
}