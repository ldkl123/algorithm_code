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
    int ans=0;
    int start=0, end=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a=0, b=0;
        scanf("%d %d", &a, &b);
        pair<int, int> p = make_pair(-a, -b);
        q.push(p); 

    }
    ans = q.size();
    priority_queue<pair<int, int> >pq;
    pair<int, int> p = q.top();
    q.pop();
    pq.push(p);
    while(!q.empty()){
        p = q.top();
        q.pop();
        if(-pq.top().second > -p.first){
            pq.push(p);
        }
        else{
            ans--;
            pq.pop();
        }
    }
    cout << ans << endl;
}