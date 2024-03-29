#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct dot{
    int x;
    int y;
};

bool map[101][101]={0,};
bool visit[101][101] = {0,};
void print_out1(int n, int m);
void print_out2(int n, int m);
void make_map(dot d1, dot d2);
int BFS(int i, int j, int N, int M);
int x_move[4] = {-1, 0, 0, 1};
int y_move[4] = {0, -1, 1, 0};
int main(){
    int N=0, M=0, K=0;
    vector<int> res;
    scanf("%d %d %d", &M, &N, &K);
    cin.ignore();
    for(int i=0; i<K; i++){
        string s;
        dot d1; dot d2;
        getline(cin, s);
        d1.x = s[0]+1-'0';
        d1.y = s[2]+1-'0';
        d2.x = s[4]-'0';
        d2.y = s[6]-'0';
        map[d1.y][d1.x]= 1;
        map[d2.y][d2.x] = 1;    
        make_map(d1, d2);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(map[j][i] == 0 && visit[j][i] == false){
                int ans = 0;
                ans = BFS(i, j, N, M);
                res.push_back(ans);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

}
 void print_out1(int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}   
void print_out2(int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
}
void make_map(dot d1, dot d2){
    queue<dot> q;
    q.push(d1);
    q.push(d2);
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i=0; i<4; i++){
            int _x = x+x_move[i]; 
            int _y = y+y_move[i]; 
            if(_x < d1.x || _x > d2.x || _y < d1.y || _y > d2.y){
                continue;
            }
            if(map[_y][_x] == 0){
                map[_y][_x] = 1;
                dot d;
                d.x = _x;
                d.y = _y;
                q.push(d); 
            }
        }   
    } 
}
int BFS(int i, int j, int N, int M){
    queue<dot>q;
    int ans=1;
    dot d;
    d.x = i;
    d.y = j;
    q.push(d);
    visit[j][i] = true;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i=0; i<4; i++){
            int _x = x+x_move[i];
            int _y = y+y_move[i];
            if(_x < 1 || _x > N || _y < 1 || _y > M){
                continue;
            }
            if(map[_y][_x] == 0 && visit[_y][_x] == false){
                visit[_y][_x] = true;
                dot d;
                d.x = _x;
                d.y = _y;
                q.push(d);
                ans++;
            }
        }
    }
    return ans;
}