#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
#include <cstdlib>
using namespace std;

int64_t padoban[101]= {0,};
int main(){
    int T=0;
    scanf("%d", &T);
    padoban[1]= 1;
    padoban[2]= 1;
    padoban[3]= 1;
    padoban[4]= 2;
    padoban[5]= 2;
    while(T>0){
        int N=0;
        scanf("%d", &N);
        if(padoban[N] != 0){
            cout << padoban[N] << "\n";
        }
        else{
            for(int i=6; i<=N; i++){
                padoban[i] = padoban[i-1] + padoban[i-5];
            }
            cout << padoban[N] << "\n";
        }
        T--;
    }
}