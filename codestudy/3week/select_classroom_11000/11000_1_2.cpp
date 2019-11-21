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
    priority_queue<pair<int, int> > q;
    int N=0;
    int size=0;
    int start=0, end=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a=0, b=0;
        scanf("%d %d", &a, &b);
        pair<int, int> p = make_pair(-a, -b);
        q.push(p); 

    }
    priority_queue<pair<int, int> >pq;
    pair<int, int> temp = make_pair(q.top().second, q.top().first);
    q.pop();
    pq.push(temp);
    while(!q.empty()){
        temp = make_pair(q.top().second, q.top().first);
        q.pop();
        if(-pq.top().first <= -temp.second){
           pq.pop();

        }
        pq.push(temp);
            
    }
    cout << pq.size() << endl;
}