#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
#include <cstdlib>
using namespace std;
typedef struct num{
    int end[10];
}Num;
void init_num(Num* n);
void dodp(Num* n, int N);
int main(){
    int N=0;
    int ans=0;
    scanf("%d", &N);
    Num* dp = new Num[N+1];
    init_num(dp);
    dodp(dp, N);
    for(int i=0; i<10; i++){
        ans+= dp[N].end[i];
    }
    cout << ans%10007 <<"\n";
    
}
void init_num(Num* n){
    for(int i=0; i<10; i++){
        n[1].end[i] = 1;
    }
}
void dodp(Num* n, int N){
    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                n[i].end[j] = (n[i].end[j] + n[i-1].end[k])%10007;
            }
        }
    }
}
