#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int map[27][27] = {0,};
bool v[27][27]={0,};
int x_move[4] = {-1, 1, 0, 0};
int y_move[4] = {0, 0, -1, 1};
void find_BFS(int n, vector<int>* num);
int num_BFS(int n, int i, int j);

int main(){
    int N=0;
    vector<int> num;
    int dep=1;

    scanf("%d", &N);
    cin.ignore();
    for(int i=0; i<N; i++){
        string s;
        getline(cin, s);
        for(int j=0; j<s.size(); j++){
            map[i+1][j+1] = s[j]-'0';
        }
    } 
    find_BFS(N, &num);
    sort(num.begin(), num.end());
    cout << num.size() << endl;
    for(int i=0; i<num.size(); i++){
        cout << num[i] << "\n";
    }
}

void find_BFS(int n, vector<int>* num){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i][j] == false && map[i][j] == 1){
                int x = num_BFS(n, i,j);
                num->push_back(x);
            }
        }
    }
}

int num_BFS(int n, int i, int j){
    int cnt=0;
    queue<pair<int, int> > q;
    pair<int, int> temp = make_pair(i, j);
    q.push(temp);
    v[i][j] = true;
    while(!q.empty()){
        cnt++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int _x = x+x_move[i];
            int _y = y+y_move[i];
            if(map[_x][_y] == 1 && v[_x][_y] == false){
                v[_x][_y] = true;
                pair<int, int> t = make_pair(_x, _y);
                q.push(t);
            }
        }

    }
    return cnt;
}