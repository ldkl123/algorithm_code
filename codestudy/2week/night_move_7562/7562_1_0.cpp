#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
int x_1[2] = {1, 2};
int y_1[2] = {2, 1};
int x_2[2] = {-1, 2};
int y_2[2] = {-2, 1};
int x_3[2] = {-2, -1};
int y_3[2] = {-1, -2};
int x_4[2] = {1, -2};
int y_4[2] = {2, -2};
int x_move[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int y_move[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int BFS(int s1, int s2, int a1, int a2, vector<vector<bool> > v);

int main(){
    int T=0;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int I=0;
        int ans=0;
        scanf("%d",&I);
        vector<vector<bool> > v(I, vector<bool>(I));
        int s1=0, s2=0;
        int a1=0, a2=0;
        scanf("%d %d", &s1, &s2);
        scanf("%d %d", &a1, &a2);
        ans = BFS(s1,s2,a1,a2,v);
        cout << ans << "\n";
    }
}
int BFS(int s1, int s2, int a1, int a2, vector<vector<bool> > v){
    pair<int, int> s = make_pair(s1, s2);
    pair<int, int> a = make_pair(a1, a2);
    int n = v.size();
    queue<pair<pair<int, int>, int> > q;
    pair<pair<int, int>, int> t = make_pair(s, 0);
    q.push(t);
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second; 
        q.pop();
        if(x == a.first && y == a.second){
            return cnt;
        }
        for(int i=0; i<8; i++){
            int _x = x+x_move[i];
            int _y = y+y_move[i];
            if(_x < 0 || _x > n-1 || _y < 0 || _y > n-1){
                continue;
            }
            if(v[_y][_x] == false){
                v[_y][_x] = true;
                pair<int, int> p = make_pair(_x, _y);
                pair<pair<int, int> , int> t = make_pair(p, cnt+1);
                q.push(t);
            }

        }
    }
}