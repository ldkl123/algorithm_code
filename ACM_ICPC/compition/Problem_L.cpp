#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>
#include <vector>
#include <math.h>

using namespace std;
bool comp(int a, int b);
int d[250][2];
int main(){
    int N=0;
    int a_t=0, b_t=0;
    cin >> N;
    priority_queue< pair<int, int> > lst;
    for(int i=0; i<N; i++){
        scanf("%d %d", &d[i][0], &d[i][1]);
        if (d[i][0] == d[i][1]){
            pair<int, int> temp = make_pair(d[i][0], d[i][1]);
            lst.push(temp);
        }
        else{
            int b_temp=0;
            int a_temp=0;
            if(b_t == a_t){
                if(comp(d[i][0], d[i][1])){
                    b_t+= d[i][1];
                }
                else{
                    a_t+=d[i][0];
                }
            }
            else{
                    
                if(comp(b_t, a_t)){
                    a_temp = d[i][0];
                    b_temp = b_t - a_t + d[i][1];

                }else{
                    a_temp = a_t - b_t + d[i][0];
                    b_temp = d[i][1];
                }

                if(comp(b_temp, a_temp)){
                    a_t+=d[i][0];
                }
                else{
                    b_t+=d[i][1];
                }
            }
            
        }
        //cout << "a_t: "<<a_t << " " << "b_t: " << b_t << " qsize: "<<lst.size()<< endl;
    } 
    while(!lst.empty()){
        if(comp(a_t, b_t)){
            b_t+= lst.top().first;
        }
        else{
            a_t+=lst.top().first;
        }
        cout << "a_t: " << a_t << " b_t: "<< b_t << endl;
        lst.pop();
    }
    //cout << max(a_t, b_t) << endl;
}
bool comp(int a, int b){
    return a > b;
}
    
