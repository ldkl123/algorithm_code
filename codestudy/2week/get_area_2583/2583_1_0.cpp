#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <math.h>
#include <cstdlib>

using namespace std;
bool map[101][101]={0,};
void print_out(int n, int m);
int main(){
    int N=0, M=0, K=0;
    scanf("%d %d %d", &M, &N, &K);
    cin.ignore();
    for(int i=0; i<K; i++){
        string s;
        getline(cin, s);
        map[s[2]+1-'0'][s[0]+1-'0']= 1;
        map[s[6]-'0'][s[4]-'0'] = 1;    
    }
    print_out(M, N);
}
void print_out(int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}