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
    for(int i=0; i<K; i++){   //입력받아서 사각형의 좌표를 map배열에 1 저장

        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        for(int j=y1+1 ; j<=y2 ; j++){
            for(int l=x1+1 ; l<=x2 ; l++){
                map[j][l]=1;
            }
        }
    }
    for(int i=1; i<=N; i++){     //실질적으로 0부분을 찾아서 칸의 개수를 구하는 루프문
        for(int j=1; j<=M; j++){
            if(map[j][i] == 0 && visit[j][i] == false){
                int ans = 0;
                ans = BFS(i, j, N, M);
                res.push_back(ans);
            }
        }
    }
    //print_out1(M,N);     // 맵 출력하는 부분
    //cout << endl;
    //print_out2(M,N);
    sort(res.begin(), res.end());  // 오름차순 정렬
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
    queue<pair<int, int> > q;
    q.push(d1);
    q.push(d2);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int _x = x+x_move[i]; 
            int _y = y+y_move[i]; 
            if(_x < d1.first || _x > d2.first || _y < d1.second || _y > d2.second){
                continue;
            }   // 사각형 좌표를 벗어나면 제외
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
                continue;   // 그리드 크기를 벗어나면 제외
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