#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
int ans=0;
void print_vector(vector<vector<bool> > v);
void find_BFS(int i, int j, vector<vector<bool> > m, vector<vector<bool> >* v, int N, int M);
void BFS(const vector<vector<bool> > m, vector<vector<bool> >* v, int N, int M);

int x_move[4] = {-1, 1, 0, 0};
int y_move[4] = {0, 0, -1, 1};
int main(){
    int T=0;
    scanf("%d", &T);
    vector<int> res;
    for(int i=0; i<T; i++){
        ans=0;
        int N=0, M=0, K=0; 
        scanf("%d %d %d", &M, &N, &K);
        vector<vector<bool> > map(N, vector<bool>(M)); 
        vector<vector<bool> > visit(N, vector<bool>(M)); 
        for(int j=0; j<K; j++){
            int a=0, b=0; 
            scanf("%d %d", &a, &b);
            map[b][a] = true;
        }
        BFS(map, &visit, N, M);
        res.push_back(ans);
    }
    for(int i=0; i<res.size(); i++){
        cout << res[i] << "\n";
    }
}
void print_vector(vector<vector<bool> > v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void BFS(const vector<vector<bool> > m, vector<vector<bool> >* v, int N, int M){
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].size(); j++){
            if(m[i][j] == 1 && (*v)[i][j] == false){
                (*v)[i][j] = true;
                find_BFS(i, j, m, v, N, M);
                ans++; 
            }
        }
    }
}
void find_BFS(int i, int j, vector<vector<bool> > m, vector<vector<bool> >* v, int N, int M){
    queue<pair<int, int> >q;
    pair<int, int> p = make_pair(i, j);
    q.push(p);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int _x = x+x_move[i];
            int _y = y+y_move[i];
            if(_x >= N || _x < 0 || _y >= M || _y < 0 ){
                continue;
            }
            if(m[_x][_y] == 1 && (*v)[_x][_y] == false){
                (*v)[_x][_y] = true;
                pair<int, int> p = make_pair(_x, _y);
                q.push(p);
            }
        }
    }
}