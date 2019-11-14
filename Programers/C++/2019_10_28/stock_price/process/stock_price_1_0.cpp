// Developed by "DoKyu Lee"
// Date: 2019.10.28
// Version: 1.0
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
    
    for(int i=0; i<n; i++){
        pair<int, int> temp = make_pair(prices[i], i);
        if(st.size() > 1 && temp.first >= st[i-1].first){
            answer[st[i-1].second]++;
        }
        while(st.size() > 1 && st.back().first > temp.first){
            answer[st.back().second]++;
            st.pop_back();
        }

        st.push_back(temp);
    }
    int N = st.size();
    for(int i=0; i<st.size(); i++){
        answer[st[i].second] += N-1;
        N--;
    }
    //print_vector(st);
    return answer;
}
// Result : 0% accuracy(100%)
