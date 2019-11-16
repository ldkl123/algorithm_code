#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
#include <stdlib.h>
using namespace std;

void swap(int* a, int* b);
int main(){
    int T=0;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int n=0, x=0, a=0, b=0;
        scanf("%d %d %d %d", &n, &x, &a, &b);
        int temp = x;
        if(a>b){
            swap(b , a);
        }
        while(a>1 && x>0){
            a--;
            x--;
        }
        while(b<n && x>0){
            b++;
            x--;
        }
        cout << abs(a-b) << endl;
    }
}
void swap(int* a, int* b){
    int* temp=0;
    temp = a;
    a = b;
    b = temp;
}