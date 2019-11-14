#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int r=0, l=0;
    string s1, s2;
    cin>>s1>>s2;
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i] == s2[j]){
                l=i; r=j;
                goto EXIT;
            }
        }
    }
    EXIT:
    for(int i=0; i<s2.size(); i++){
        if(i==r){
            cout << s1 << endl;
        }
        else{
            for(int j=0; j<s1.size(); j++){
                if(j == l){
                    cout << s2[i];
                }
                else{
                    cout << ".";
                }
            }
            cout<<endl;
        }
    }
}