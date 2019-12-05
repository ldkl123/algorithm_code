#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

bool judge(int* lst, int mid, int N, int M);
int main(){
    int N=0, M=0;
    int sum=0;
    int count=0;
    int ans=0;
    scanf("%d %d", &N, &M);
    int* lst = new int[N+1];
    for(int i=1; i<=N; i++){
        scanf("%d",&lst[i]);
        sum += lst[i];
    }
    int high = sum;
    int low=1;
    while(low <= high){
        int mid = (high + low)/2;
        if(judge(lst, mid, N, M)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}
bool judge(int* lst, int mid, int N, int M){
    int sum = 0;
    int count=1;
    for(int i=1; i<=N; i++){
        if(lst[i] > mid){
            return false;
        }
        if(sum+lst[i] > mid){
            sum=0;
            count++; 
        }
        sum+=lst[i];
    }
    return M>=count;
}