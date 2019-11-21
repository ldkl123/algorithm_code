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
    int N=0;
    int B=0, C=0;
    int ans=0;
    scanf("%d", &N);
    int* people = new int[N];
    for(int i=0; i<N; i++){
        scanf("%d", people+i);
    }
    scanf("%d %d", &B, &C);
    for(int i=0; i<N; i++){
        int num=1;
        int temp = people[i] - B;  
        if(temp> 0){
            num+= temp/C;
            if(temp%C > 0){
                num++;
            }
        }
        ans+=num;
    }
    cout << ans << "\n";
}