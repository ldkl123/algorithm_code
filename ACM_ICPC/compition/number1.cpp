#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>
#include <vector>

using namespace std;

int main(){
    long _input;
    cin >> _input;
    
    int answer = 2;

    for(int i=2; i<=_input; i++){
        if(i%2 == 1){
            answer = (2*answer)%16769023;
        }
    }
    cout << answer << endl;
}