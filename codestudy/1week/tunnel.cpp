#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n=0, m=0;
    int ans=0;
    cin>>n;
    cin>>m;
    ans = m;
    for(int i=0; i<n; i++){
        int temp1, temp2;
        cin>> temp1 >> temp2;
        m = m + temp1 - temp2;
        if(m < 0){
            ans=0;
            break;
        }
        if(m > ans){
            ans = m;
        }
    }
    cout << ans  << endl;
}