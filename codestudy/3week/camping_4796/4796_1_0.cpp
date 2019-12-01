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
    int L=0, P=0, V=0;
    int cnt=0;
    while(1){
        int ans=0;
        int num=0;
        int least=0;
        scanf("%d %d %d", &L, &P, &V);
        if(L==0){
            break;
        }
        num = V/P;
        least = V%P;
        if(least < L){
            ans+= least;
        }
        else{
            num+=1;
        }

        ans+=num*L; 
        
        cnt++;

        cout << "Case "<< cnt << ": "<< ans <<"\n";
    }
}
 