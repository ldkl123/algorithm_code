/*
Developed by "DoKyu Lee"
Date: 2019.09.25
Version: 1.3
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
#define compare_k(a, b)(a <= b ? true:false)

using namespace std;

// Functions
void print_pq(priority_queue<int> pq);
void print_list(vector<int> q);
int find_min(vector<int> q);
int find_max(vector<int> q);


int main(){
    // variables
    int n=0, K=0, n_k=0, ans=0;
    int b=0, s=0, margin=0;;
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
    cout << "s: " << s << " b: "<< b << endl;
    // Main code
    int n_copy = n;
    for(int i=s; i<=b; i++){  
        int j=n-n_copy;
        int count=0;

        K = i;
        n_k = n-K;
        while(j < n_copy){
            if(compare_k(K, paper[j])){
                margin++;
                n_copy--;                     
                break;
            }
            count++;
            j++;                      // j have to be increase to get out while loop
        }
        cout << "K: " << K << "  margin: " << margin << endl;
        cout << "n-count: " << n-count << " count+1: " << count+1<<endl;
        if (n-count >=K && n_k <= margin-1){
            ans = K;
            break;
        }
    }
    cout << "answer: " <<ans << endl;
    
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


// Result: new test case(2, (100, 1001)) dosen't work