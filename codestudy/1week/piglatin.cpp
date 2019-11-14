#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
string piglatin(string first, string mod, bool flag);

char collection[5] = {'a', 'e', 'i', 'o', 'u'};

int main(){
    
    while(1){
        string s;
        cin >> s;
        if(s.compare("#") == 0){
            break;
        }
        cout << piglatin(s, s, 0) << endl;
    }
}

string piglatin(string first, string mod, bool flag){
    if(first.compare(mod)==0 && flag){
        return first+"ay";
    }
    for(int i=0; i<5; i++){
        if(collection[i] == mod[0]){
            return mod+"ay";
        }
    }
    return piglatin(first, mod.substr(1)+mod[0], 1);
}