#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
void DFS(vector<int> lotto);
void _DFS(pair<int, int> s, vector<int> lotto, vector<pair<int, int> > lst);
int main(){
    while(true){
        int N=0;
        scanf("%d", &N);
        if(N==0){
            break;
        }
        vector<int> v;
        for(int i=0; i<N; i++){
            int x=0;
            scanf("%d", &x);
            v.push_back(x);
        }
        DFS(v);
        cout << "\n";
    }
}

void DFS(vector<int> lotto){
    int n = lotto.size();
    for(int i=0; i<n-5; i++){
        pair<int, int> p = make_pair(i, lotto[i]);
        vector<pair<int, int> > v;
        v.push_back(p);
        _DFS(p, lotto,v);
    }
}
void _DFS(pair<int, int> s, vector<int> lotto, vector<pair<int, int> > lst){
    int n = lotto.size();
    int end=0;
    if(lst.size() == 6){
        for(int i=0; i<lst.size(); i++){
            cout << lst[i].second << " ";
        }
        cout << endl;
        return;
    }
    for(int i=s.first+1; i<= lst.size()+n-6; i++){
        pair<int, int> p = make_pair(i, lotto[i]);
        lst.push_back(p);
        _DFS(p, lotto, lst);
        lst.pop_back();
    }
}
