#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
int H[100001] = {0,};
int heap_del(int s);
void heap_insert(int x, int s);
void print_out(int s);
int main(){
    int N=0;
    int s=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x=0;
        scanf("%d", &x);
        if(x==0){
            if(s == 0){
                cout << 0<< "\n";
            }
            else{
                x = heap_del(s);
                s--;
                //print_out(s);
                cout << x << "\n";
            }
        }
        else{
            heap_insert(x, s);
            s++;
            //print_out(s);
        }
        //cout << "size :" << s << endl;
    }    
}

int heap_del(int s){
    int idx=0;
    int ans = H[idx];
    H[idx] = H[s-1];
    H[s-1] = 0;
    s--;
    while(idx < s){
        int left = 2*idx+1;
        int right = 2*idx+2;
        if(left >= s || right >= s){
            break;
        }
        int small = (H[left] > H[right]) ? right : left;
        if(H[idx] > H[small]){
            int temp = H[idx];
            H[idx] = H[small];
            H[small] = temp;
            idx = small;
        }
        else{
            break;
        }
    }
    return ans;
}

void heap_insert(int x, int s){
    int idx = s;
    H[idx] = x;
    if(s==0){
        H[0] = x;
    }
    while(idx > 0){
        int parent = (idx-1)/2;
        if(H[parent] > H[idx]){
            int temp = H[parent];
            H[parent] = H[idx];
            H[idx] = temp;
            idx = parent;
        }
        else{
            break;
        }
    }
    

}
void print_out(int s){
    for(int i=0; i<s; i++){
        cout << H[i] << " ";
    }
    cout << endl;
}