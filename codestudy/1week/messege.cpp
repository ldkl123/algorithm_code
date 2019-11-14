#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int P=0, W=0;
    int ans=0, cnt=1;
    vector<vector<char> > button;
    vector<char> temp;
    for(int i='A'; i<='Z'; i++){
        temp.push_back(char(i));
        if((char)i == 'R' || (char)i == 'Y'){
            cnt--;
        }
        if(cnt%3==0){
            button.push_back(temp);
            temp.clear();
            cnt=0;
        }
        cnt++;
    }
    string s;
    int prev=-1;
    scanf("%d %d", &P, &W);
    cin.ignore(256, '\n');
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            ans+=P;
            prev=-1;
        }
        else{
            for(int j=0; j<button.size(); j++){
                if(button[j].front() <= s[i] && button[j].back() >= s[i]){
                    ans+=P;
                    if(prev == j){
                        ans+=W;
                    }
                    else{
                        prev = j;
                    }
                    for(int k=0; k<button[j].size(); k++){
                        if(button[j][k] == s[i]){
                            goto EXIT;
                        }
                        else{
                            ans+=P;
                        }
                    }
                }
            }
            EXIT:
            continue;
        }
    }
    cout << ans <<endl;
}