#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

bool map[101][101]={0,};
bool visit[101][101] = {0,};
void print_out1(int n, int m);
void print_out2(int n, int m);
void make_map(pair<int, int> d1,  pair<int, int> d2);
int BFS(int i, int j, int N, int M);
int x_move[4] = {-1, 0, 0, 1};
int y_move[4] = {0, -1, 1, 0};
int main(){
    int N=0, M=0, K=0;
    vector<int> res;
    scanf("%d %d %d", &M, &N, &K);
    cin.ignore();
    for(int i=0; i<K; i++){
        vector<int> v;
        for(int j=0; j<4; j++){
            int temp=0;
            cin>>temp;
            v.push_back(temp);
        } 
        pair<int, int> d1 = make_pair(v[0]+1, v[1]+1); 
        pair<int, int> d2 = make_pair(v[2], v[3]); 
        map[d1.second][d1.first]= 1;
        map[d2.second][d2.first] = 1;    
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
    //print_out1(M,N);
    //cout << endl;
    //print_out2(M,N);
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
void make_map(pair<int, int> d1, pair<int, int> d2){
    queue<pair<int, int> t> q;
    q.push(d1);
    q.push(d2);
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i=0; i<4; i++){
            int _x = x+x_move[i]; 
            int _y = y+y_move[i]; 
            if(_x < d1.first || _x > d2.first || _y < d1.second || _y > d2.second){
                continue;
            }
            if(map[_y][_x] == 0){
                map[_y][_x] = 1;
                pair<int, int> d = make_pair(_x, _y); 
                q.push(d); 
            }
        }   
    } 
}
int BFS(int i, int j, int N, int M){
    queue<pair<int, int> >q;
    int ans=1;
    pair<int, int> d = make_pair(i, j);
    q.push(d);
    visit[j][i] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int _x = x+x_move[i];
            int _y = y+y_move[i];
            if(_x < 1 || _x > N || _y < 1 || _y > M){
                continue;
            }
            if(map[_y][_x] == 0 && visit[_y][_x] == false){
                visit[_y][_x] = true;
                pair<int, int> d = make_pair(_x, _y); 
                q.push(d);
                ans++;
            }
        }
    }
    return ans;
}