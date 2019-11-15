#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

bool table[101][101]={0,};
queue<pair<int, int> >q;
void BFS(int n);
void DFS(int st, int start, int end, int n, vector<vector<bool> >* v);
void print_out(int N);
void check_one(int N);
int main(){
    int N=0;
    scanf("%d", &N);
    cin.ignore();
    for(int i=0; i<N; i++){
        string s;
        int margin=0;
        getline(cin, s);
        for(int j=0; j<s.size(); j++){
            if(s[j] != ' '){
                table[i][j-margin] = s[j]-'0';
            }
            else{
                margin++;
            }
        }
    }
    check_one(N);
    while(!q.empty()){
        vector<vector<bool> > v(N, vector<bool>(N, 0));
        int start = q.front().first;
        int end = q.front().second;
        q.pop();
        DFS(start, start, end, N, &v);
    }
    print_out(N);
}
void DFS(int st, int start, int end, int n, vector<vector<bool> >* v){
    table[st][end] = true;
    (*v)[start][end] = true;
    for(int i=0; i<n; i++){
        if(table[end][i] == 1 && (*v)[end][i] == false && end != i){
            DFS(st, end, i, n, v);
        }
    }
}

void check_one(int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(table[i][j] == 1){
                pair<int, int> p = make_pair(i, j);
                q.push(p);
            }
        }
    }
}
void print_out(int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

}