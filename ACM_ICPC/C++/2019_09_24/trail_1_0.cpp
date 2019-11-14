/*
Developed by "DoKyu Lee"
Date: 2019.09.24
Version: 1.0
*/

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>
#include <vector>

#define max(a, b)(a > b ? a:b)
#define min(a, b)(a < b ? a:b)

using namespace std;
void print_pq(priority_queue< pair<int, int> > pq);
int main(){
    // variable
    int n=0, d=0, answer=0;
    priority_queue< pair<int, int> > line_lst;
    priority_queue< pair<int, int> > pq;
    
    // Get line data
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b;
        int left, right;
        scanf("%d %d", &a, &b);
        left = min(a, b);
        right = max(a, b);
        pair<int, int> temp = make_pair(-left, -right);
        line_lst.push(temp);
    }
    scanf("%d", &d);    
    print_pq(line_lst);

    // Main algorithm

    for(int i=0; i<n; i++){
        pq.push(line_lst.top());
        while(!pq.empty() && -pq.top().first < -line_lst.top().second - d) pq.pop();
        line_lst.pop();
        answer = max(answer, pq.size());
    }
    cout << answer << endl;;
}

void print_pq(priority_queue< pair<int, int> > pq){
    while(!pq.empty()){
        cout << "("<< -pq.top().first <<", " << -pq.top().second<<") ";
        pq.pop(); 
    }
    cout<<endl;
}