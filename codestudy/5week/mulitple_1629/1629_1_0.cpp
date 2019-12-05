#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

 __int64_t DAC(__int64_t A, __int64_t front, __int64_t tail, __int64_t C);
int main(){
    __int64_t A=0, B=0, C=0;
    scanf("%d %d %d", &A, &B, &C);
    if(B==1){
        cout << A%C << "\n";
    }
    else if(B%2 == 0){
        cout << DAC(A, 0, B-1, C) << "\n";
    }
    else{
        __int64_t a = DAC(A, 0, B-2, C );
        cout << ((a%C)*(A%C))%C << "\n";
    }

}

 __int64_t DAC(__int64_t A, __int64_t front, __int64_t tail, __int64_t C){
    if(front < tail){
        __int64_t a=0, b=0;
        __int64_t mid=0;
        mid = (front+tail)/2;
        a = DAC(A, front, mid, C);
        b = DAC(A, mid+1, tail, C);
        return ((a%C)*(b%C))%C;      
    }
    else{
        return A%C; 
    }
}