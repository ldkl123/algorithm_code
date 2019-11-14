// Developed by "DoKyu Lee"
// Date: 2019.10.28
// Version: 1.2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
    
using namespace std;

void print_vector(vector<pair<int, int> > v){
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " ";
    }
    cout << endl;
}

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    vector<pair<int, int> > st;
    // initial stack
    pair<int, int> temp = make_pair(prices[0], 0);
    st.push_back(temp);
    
    // main
    for(int i=1; i<n; i++){
        print_vector(st);
        temp = make_pair(prices[i], i);
        while(st.size() > 0 && st.back().first > temp.first){
            answer[st.back().second]++;
            st.pop_back();
        }
        for(int j=0; j<st.size()-1; j++){
            answer[s[j].second]++;
        }

        st.push_back(temp);
    }
   
    return answer;
}
