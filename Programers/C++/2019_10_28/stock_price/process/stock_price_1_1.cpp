// Developed by "DoKyu Lee"
// Date: 2019.10.28
// Version: 1.1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
    
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    vector<pair<int, int> > st;
    // initial stack
    pair<int, int> temp = make_pair(prices[0], 0);
    st.push_back(temp);
    
    // main
    for(int i=1; i<n; i++){
        temp = make_pair(prices[i], i);
        if(st.size() > 0 && temp.first >= st.back().first){
            answer[st.back().second]++;
        }
        while(st.size() > 0 && st.back().first > temp.first){
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
    return answer;
}
