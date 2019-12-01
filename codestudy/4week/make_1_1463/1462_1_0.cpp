#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
void dodp(int* dp, int N);
int main(){
    int N=0;
    scanf("%d", &N);
    int* dp = new int[N+1];
    dodp(dp, N);
    cout << dp[N] << "\n";
    
}

void dodp(int* dp, int N){
    dp[1] = 0;
    unsigned int num = 1 << 30;
    for(int i=2; i<=N; i++){
        int three[2] = {0,};
        if(i%3 == 0){
            three[0] = dp[i/3] + 1;
        }
        else{
            three[0] = num;
        }
        if(i%2 == 0){
            three[1] = dp[i/2]+1;
        }
        else{
            three[1] = num;
        }
        three[0] = (three[0] > three[1]) ? three[1] : three[0];
        dp[i] = (three[0] > dp[i-1] + 1) ? dp[i-1]+1 : three[0];
    }
}