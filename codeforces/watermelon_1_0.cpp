#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int N=0;
    bool flag=false;
    scanf("%d", &N);
    for(int i=2; i<100; i+=2){
        if((N-i)%2==0 && N-i > 0){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "YES"<<endl;
    }
    else{
        cout << "NO"<<endl;
    }
}
