/*
Developed by "DoKyu Lee"
Date: 2019.09.25
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
#define compare_k(a, b)(a < b ? true:false)

using namespace std;

// Functions
void print_pq(priority_queue<int> pq);
void print_list(vector<int> q);
int find_min(vector<int> q);
int find_max(vector<int> q);


int main(){
    // variables
    int n=0, K=0, n_k=0, ans=0;
    int b=0, s=0;
    vector<int> paper;
    
    // get input and sort
    scanf("%d" , &n);
    for(int i=0; i<n; i++){
        int temp=0;
        scanf("%d", &temp);
        paper.push_back(temp);
    }

    // Sorting
    sort(paper.begin(), paper.end());
    // find the biggest and the smallest number
    s = paper[0];
    b = paper[n-1];
    // compare size and biggest quote number to fin minimum number
    b = min(n, b);

    // Main code
    int n_copy = n;
    for(int i=s; i<=b; i++){
        int j=n-n_copy;
        int count=0;

        K = i;
        n_k = n-K;
        while(j < n_copy){
            if(compare_k(K, paper[j])){
                n_copy--;
                break;
            }
            count++;
        }
        if (count >=K && n_k <= n-count){
            ans = K;
            break;
        }
    }
    cout << ans << endl;
    /*
    print_list(paper);
    cout << endl;
    cout << s <<" " << b;
    cout << endl;
    */
}

void print_pq(priority_queue<int> pq){
    while(!pq.empty()){
        cout << "("<< -pq.top() <<") ";
        pq.pop(); 
    }
    cout<<endl;
}
void print_list(vector<int> q){
    int size = q.size();
    for(int i=0; i<size; i++){
        cout << q[i] << " ";
    }
    cout << endl;
}

// Reuslt: infinite loop