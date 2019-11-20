#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int N=0; 
    vector<int> v;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int temp=0;
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
}