#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int H[1000001] = {0,};
int list[10000001] = {0,};
int H_size = 0;

void Compare(int idx){
    int parent=0;
    int child = idx;

    while(child > 0){
        parent = (child-1)/2;
        if(H[parent] > H[child]){
            int temp = H[child];
            H[child] = H[parent];
            H[parent] = temp;
        }
        child = parent;
    }
}

void heap_sort(int* list, int size){
    for(int i=0; i<size; i++){
        H[i] = list[i];
        Compare(i);
    }

}

int heap_delete(){
    int root = H[0]; 
    H[0] = H[H_size-1];
    H[H_size-1] = 0;
    H_size--;
    
    int parent = 0;
    int leftchild, rightchild;
       

    while(2*parent+1 < H_size){
        leftchild = 2*parent+1;
        rightchild = 2*parent+2;
        int min=0;

        if(leftchild == H_size-1){
            min = leftchild;
        }
        else{
            if(H[leftchild] >= H[rightchild]){
                min = rightchild;
            }
            else{
                min = leftchild;
            }
        }
        if(H[parent] > H[min]){
            int temp = H[min];
            H[min] = H[parent];
            H[parent] = temp;

        }
        else{
            break;
        }

        parent = min;
    }

    return root;
}

void heap(int* list, int size){
    heap_sort(list, size);
    for(int i=0; i<size; i++){
        list[i] = heap_delete();
    }
}



int main(){
    int N=0;
    scanf("%d", &N);
    int size = N;
    H_size = size;

    for(int i=0; i<size; i++){
        scanf("%d", list+i);
    }

    heap(list, size);
    
    for(int i=0; i<size; i++){
        cout << list[i]<<" ";
    }
    
    cout <<"\n";
}