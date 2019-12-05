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
    if(B==1){
        cout << A%C << "\n";
    }
    else if(B%2 == 0){
        cout << DAC(A, B, C) << "\n";
    }
    else{
        __int64_t a = DAC(A, B-1, C );
        cout << ((a%C)*(A%C))%C << "\n";
    }

}

 __int64_t DAC(__int64_t A, __int64_t B, __int64_t C){
    if(B!=1){
        __int64_t a=0;
        a = DAC(A, B/2, C);
        return ((a%C)*(a%C))%C;      
    }
    else{
        return A%C; 
    }
}