#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

bool map[1001][1001]={0,};
bool v[1001]={0,};

void DFS(int start, int n);
int main(){
   int N=0, M=0;
   int ans=0;
   scanf("%d %d", &N, &M);
   for(int i=0; i<M; i++){
       int x=0, y=0;
       scanf("%d %d", &x, &y);
       map[x][y] = 1;
   }
   for(int i=1; i<=N; i++){
       if(v[i] == false){
           DFS(i, N);
           ans++;
       }
   } 
   cout << ans << endl;
}
void DFS(int start, int n){
    for(int i=1; i<=n; i++){
        if(map[start][i] == 1 && v[i] == false && start != i){
            v[i] = true; 
            DFS(i, n);
        }
    }
}
