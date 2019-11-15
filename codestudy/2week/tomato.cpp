#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;
void BFS(int N, int M);
bool check_is_right(int n, int m);
void check_tomato(int N, int M);
int x_move[4] = {-1, 1, 0, 0};
int y_move[4] = {0, 0, -1, 1};
int tomato[1001][1001] = {0,};
bool v[1001][1001] = {0,};
int cnt=0;
bool init_flag=false;
queue<vector<int> > q; 
int main(){
    int N=0, M=0;
    int margin=0;
    bool minus=false;
    scanf("%d %d", &M, &N);
    cin.ignore();
    for(int i=0; i<N; i++){
        string s;
        margin=0;
        getline(cin, s);
        for(int j=0; j<s.size(); j++){
            if(s[j] != ' '){
                if(minus){
                    tomato[i][j-margin] =  -s[j]+'0';
                    minus = false;
                }
                else{
                    if(s[j] == '-'){
                        margin++; 
                        minus = true;
                    }
                    else{
                        tomato[i][j-margin] = s[j]-'0';
                    }
                }
            }
            else{
                margin++;
            }
        }
    }
    
    check_tomato(N, M);
    if(q.empty()){
        cout<< -1 << endl;
        return 0;
    }
    BFS(N, M);
    if(check_is_right(N,M)){
        cout << cnt << endl;
    }
    else{
        
        cout << -1 << endl;
    }
    
}
void check_tomato(int N, int M){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
           if(tomato[i][j] == 1){
               vector<int> p;
               p.push_back(i);
               p.push_back(j);
               p.push_back(0);
               q.push(p); 
               v[i][j]=true;
            if(tomato[i][j] == 0){
                init_flag = true;
            }
           } 
        }
    }
}
void BFS(int N, int M){
   while(!q.empty()){
       int x = q.front()[0];
       int y = q.front()[1];
       cnt = q.front()[2];
       q.pop();
       for(int i=0; i<4; i++){
           if(x+x_move[i] >= N || x+x_move[i] < 0 || y+y_move[i] >= M || y+y_move[i] < 0){
               continue;
           }
           if(tomato[x+x_move[i]][y+y_move[i]] == 0 && v[x+x_move[i]][y+y_move[i]] == false ){
                v[x+x_move[i]][y+y_move[i]] = true; 
                tomato[x+x_move[i]][y+y_move[i]] = 1; 
                vector<int> p;
                p.push_back(x+x_move[i]);
                p.push_back(y+y_move[i]);
                p.push_back(cnt+1);
                q.push(p);
           }
       }
   }
}
bool check_is_right(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tomato[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}