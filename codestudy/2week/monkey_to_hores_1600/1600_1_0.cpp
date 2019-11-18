#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
bool map[201][201] = {0,};
int x_move[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int y_move[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int BFS(int w, int h, vector<vector<bool> > v, int k);
int main(){
    int K=0;
    int W=0, H=0;
    int ans=0;
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    cin.ignore();
    vector<vector<bool> > v(H, vector<bool>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            scanf("%d", &map[i][j]);
        }
    } 
    ans = BFS(W, H, v, K);
    cout << ans << endl; 
}
int BFS(int w, int h, vector<vector<bool> > v, int k){
    queue<vector<int> > q;
    vector<int> cord;
    cord.push_back(0);  
    cord.push_back(0);  
    cord.push_back(0);  
    cord.push_back(k);  
    q.push(cord);
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        int _k = q.front()[3];
        q.pop();
        if(x == w-1 && y == h-1){
            return cnt;
        }
        if(_k>0){
            for(int i=0; i<8; i++){
                int _x = x+x_move[i];
                int _y = y+y_move[i];
                if(_x < 0 || _x > w-1 || _y < 0 || _y > h-1){
                    continue;
                }
                if(map[_y][_x] == 0 && v[_y][_x] == false){
                    v[_y][_x] = true; 
                    vector<int> c;
                    c.push_back(_x);  
                    c.push_back(_y);  
                    c.push_back(cnt+1);  
                    c.push_back(_k-1);  
                    q.push(c); 
                }
           
            }
        }
        else{
            for(int i=0; i<4; i++){
                int _x = x+dx[i];
                int _y = y+dy[i];
                if(_x < 0 || _x > w-1 || _y < 0 || _y > h-1){
                    continue;
                }
                if(map[_y][_x] == 0 && v[_y][_x] == false){
                    v[_y][_x] = true; 
                    vector<int> c;
                    c.push_back(_x);  
                    c.push_back(_y);  
                    c.push_back(cnt+1);  
                    c.push_back(_k);  
                    q.push(c); 
                }
           
            }

        }

    } 
}