#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<algorithm>

#define max(a, b)(a >b ? a: b)
#define min(a, b)(a <b ? a: b)

using namespace std;
void print_queue(queue< pair<int, int> > q);
void print_p_queue(priority_queue<int> pq);
int main(){
    queue< pair<int, int> > q;
    priority_queue<int> pq;
    pq.push(8);
    pq.push(1);
    pq.push(3);
    pq.push(5);

    q.push(make_pair(1,2));

    int a = 2, b = 3;
    pair<int, int> p = make_pair(a, b);
    q.push(p);

    cout << q.front().first << ' '<< q.front().second << endl;
    print_queue(q);
    print_p_queue(pq);
}
void print_p_queue(priority_queue<int> pq){
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
void print_queue(queue< pair<int, int> > q){
    while (!q.empty())
    {
        cout << "("<<q.front().first << ", " << q.front().second << "), ";
        q.pop();
    }
    cout << endl;
}