#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
// Counting sort
int main(){
    int N=0;
    scanf("%d", &N);



    int count[10001] = {0,};
    int countSum[10001] = {0,};  
    int sum=0;

    for(int i=1; i<=N; i++){
        int temp = 0;
        scanf("%d", &temp);
        countSum[temp]++;
    }

    for(int i=1; i<=10000; i++){
        if(countSum[i] > 0){
            while(countSum[i] > 0){
                cout << i << "\n";
                countSum[i]--;
            }
        }
    }

}