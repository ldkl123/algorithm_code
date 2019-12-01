
#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef struct stair{
    int end_1;
    int end_2;
    int max_num=0;
}Stair;
int main(){
    int N=0;
    scanf("%d", &N);
    Stair* dp = new Stair[N+1];
    dp[0].end_1 = 0;
    dp[0].end_2 = 0;
    for(int i=1; i<=N; i++){
        int sc = 0;
        scanf("%d", &sc);
        if(i==1){
            dp[1].end_1 = sc;
            dp[1].end_2 = sc;
            continue;
        }
        dp[i].end_2 = (dp[i-2].end_1 > dp[i-2].end_2) ? dp[i-2].end_1 + sc : dp[i-2].end_2 + sc;  
        dp[i].end_1 = dp[i-1].end_2 + sc;  
        dp[i].max_num = max(dp[i].end_1, dp[i].end_2);
        //cout << dp[i].end_1 << ", " << dp[i].end_2 << "\n";
    }
    cout << dp[N].max_num << "\n";
}