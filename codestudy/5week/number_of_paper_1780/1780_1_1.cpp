#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

void DO(int** M, int* ans, int N);
void print_out(int** M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    int N=0;
    int ans[3]={0,};
    scanf("%d", &N);
    int** Matx = new int*[N];
    for(int i=0; i<N; i++){
        Matx[i] = new int[N];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &Matx[i][j]);
        }
    }
    DO(Matx, ans, N);
    for(int i=0; i<3; i++){
        cout << ans[i] <<"\n";
    }
}
bool judge(int** M, int* ans, int N){
    int prev = M[0][0];                  // Judge if this matrix is full of same number was wrong
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(prev != M[i][j]){
                return false;
            }
            prev = M[i][j];
        }
    }
    if(M[0][0] == -1){
        ans[0]++;
    }
    else{
        ans[M[0][0]+1]++;
    }
    return true;
}
void DO(int** M, int* ans, int N){
    if(judge(M, ans, N) == false){
        int nN = N/3;
        if(nN == 1){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    if(M[j][k] == -1){
                        ans[0]++;
                    }
                    else{
                        ans[M[j][k]+1]++;
                    }
                }
            }
        }
        else{
            for(int i=0; i<9; i++){
                    
                int** X = new int*[nN];
                for(int j=0; j<nN; j++){
                    X[j] = new int[nN];
                }
                int r=0, c=0;
                for(int j=3*(i/3); j<3*(i/3)+nN; j++){
                    c=0;
                    for(int k=3*(i%3); k<3*(i%3)+nN; k++){
                        X[r][c] = M[j][k];
                        c++;
                    }
                    r++;
                }
                print_out(X, nN);
                cout << "\n";
                DO(X, ans, nN);
            }
        }
    }
} 
