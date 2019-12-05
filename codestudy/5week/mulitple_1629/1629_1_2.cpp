#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

 __int64_t DAC(__int64_t A, __int64_t B, __int64_t C);
int main(){
    __int64_t A=0, B=0, C=0;
    scanf("%d %d %d", &A, &B, &C);
    cout << DAC(A, B, C) << "\n";
}

 __int64_t DAC(__int64_t A, __int64_t B, __int64_t C){
    if(B!=1){
        if(B%2==0){
            return ((DAC(A, B/2, C))%C * DAC(A, B/2, C))%C;
        }
        else{

            return ((DAC(A, (B-1)/2, C))%C * (DAC(A, (B-1)/2, C))%C*A)%C;
        }
    }
    else{
        return A%C; 
    }
}