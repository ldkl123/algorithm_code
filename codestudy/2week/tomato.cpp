#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

int tomato[1001][1001] = {0,};

int main(){
    int N=0, M=0;
    bool minus=false;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        string s;
        getline(cin, s);
        for(int j=0; j<s.size(); j++){
        if(s[j] != ' '){
                if(minus){
                    tomato[i][j] = -(s[j]-'0');
                    minus = false;
                }
                if(s[j] == '-'){
                    minus = true;
                }
                else{
                    tomato[i][j] = s[j]-'0';
                }
            }
        }       
    }
    return 0;
}