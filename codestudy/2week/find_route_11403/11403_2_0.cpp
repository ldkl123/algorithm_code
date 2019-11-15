#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

bool table[101][101]={0,};
bool ans[101][101]={0,};
queue<pair<int, int> >q;
void DFS(int start, int end, int n,vector<bool>* v);
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
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(table[i][j] == 1){
                vector<bool> v(N);
                DFS(i, j, N, &v);
            }
        }
    }
    print_out(N);
}
void DFS(int start, int end, int n, vector<bool>* v){
    ans[start][end] = true;
    for(int i=0; i<n; i++){
        if(table[end][i] == 1 && (*v)[i] == false){
            (*v)[i]=true; 
            DFS(start, i, n, v);
        }
    }
}

void print_out(int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}