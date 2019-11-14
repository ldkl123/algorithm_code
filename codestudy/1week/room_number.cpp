#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>
#define EOF -1
using namespace std;

bool check_is_dup(string s);

int main(){
    int N=0, M=0;
    int ans=0;
    while(scanf("%d %d", &N, &M) != EOF){
        ans=0;
        for(int i=N; i<=M; i++){
            stringstream __s;
            string s;
            __s << i;
            s = __s.str();
            if(check_is_dup(s)){
                ans++;
            }
        }
        cout << ans << endl;
    }
}

bool check_is_dup(string s){
    int n=s.size();
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n; j++){
            if(s[i] == s[j]){
                return false;
            }
        }
    }
    return true;
}