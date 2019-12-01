#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
#include <cstdlib>
using namespace std;

int main(){
    int N=0;
    scanf("%d", &N);
    int64_t* fibo = new int64_t[N+1];
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i=3; i<=N; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[N] << "\n";
}