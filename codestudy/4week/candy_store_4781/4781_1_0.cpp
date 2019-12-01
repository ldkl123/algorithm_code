#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef struct candy{
    int cal;
    int price;
}Candy;
int dodp(Candy* C, int* dp, int N, int M);
int main(){
    while(true){
        int N=0;
        float M=0.;
        scanf("%d %f", &N, &M);
        if(N==0 && M == 0.00){
           break; 
        }
        int* dp = new int[(int)(100*M)+1];
        Candy* C = new Candy[N+1];
        for(int i=1; i<=N; i++){
            float price=0.;
            scanf("%d %f", &C[i].cal, &price);
            C[i].price = (int)(100*price);
        }
        cout << dodp(C, dp, N, (int)(100*M)) << "\n";

    }
}
int dodp(Candy* C, int* dp, int N, int M){
    for(int i=1; i<=N; i++){
        for(int j = C[i].price; j<=M; j++){
            dp[j] = max(dp[j], dp[j - C[i].price] + C[i].cal);
        }
    }
    return dp[M];
}