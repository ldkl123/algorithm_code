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
    start = -q.top().first;
    end = -q.top().second;
    ans++;
    q.pop();
    size = q.size();
    for(int i=0; i<size; i++){
        if(end > -q.top().first){
            ans++;
        }
        else{
            end = -q.top().second;
        }
        q.pop();
    }
    cout << ans << endl;    
}