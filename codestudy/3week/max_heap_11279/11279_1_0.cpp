#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int H[100001]={0,};
int heap_del(int& s);
void heap_insert(int x, int& s);
void swap(int* a, int* b);

void print_out(int s){
    for(int i=0; i<s; i++){
        cout << H[i] << " ";
    }
    cout << "\n";
}
int main(){
    int N=0;
    int s=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x=0;
        scanf("%d", &x);
        if(x==0){
            if(s==0){
                cout << 0 << "\n";
            }
            else{
                x = heap_del(s);
                
                cout << x << "\n";
            }
        }
        else{
            heap_insert(x, s);
            
        }
        //print_out(s);
    }
}
int heap_del(int& s){
    int idx=0;
    int ans=H[idx];
    H[idx] = H[s-1];
    s--;
    while(idx < s){
        int left = 2*idx+1;
        int right = 2*idx+2;
        int big=0;
        if(left >=s){
           break; 
        }
        if(right >= s){
            big = left;
        }
        else{
            big = (H[left] > H[right]) ? left : right;
        }
        if(H[big] > H[idx]){
            swap(&H[big], &H[idx]);
            idx = big;
        }
        else{
            break;
        }
    }
    return ans;
}
void heap_insert(int x, int& s){
    int idx = s;
    H[idx] = x;
    s++;
    if(s==0){
        H[0] = x;
    }
    while(idx > 0){
        int parent = (idx-1)/2;
        if(H[idx] > H[parent]){
            swap(&H[idx], &H[parent]);
            idx = parent;
        }
        else{
            break;
        }
    }
}
void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}