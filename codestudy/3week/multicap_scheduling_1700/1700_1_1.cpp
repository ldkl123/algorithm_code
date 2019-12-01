#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int N=0, K=0;
    scanf("%d %d", &N, &K);
    int* table = new int[K+1];
    int* count = new int[K+1];
    bool* enable = new bool[K+1];
    int use = 0;
    int ans=0;
    for(int i=1; i<=K; i++){
        scanf("%d", table+i);
        count[table[i]]++;
    }
    for(int i=1; i<=K; i++){
        if(use < N){
            if(enable[table[i]] == false){
                use++;
                enable[table[i]] = true;
            }
        }
        else{
            if(enable[table[i]] == false){
                ans++;
                int low_use=-1;
                for(int j=1; j<=K; j++){
                    if(enable[j] == true){
                        if(low_use == -1 || count[low_use] > count[j]){
                            low_use = j;
                        }
                    }
                }
                enable[low_use] = false;
                enable[table[i]] = true;
            }
        }
        count[table[i]]--;
    }
    cout << ans << "\n";
}