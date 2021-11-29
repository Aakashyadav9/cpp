//the Stock span problem using stack
#include<bits/stdc++.h>
using namespace std;

vector<int> stock(vector<int> prices){
    vector<int> ans;
    stack<pair<int, int>> st;
    for(auto price: prices){
        int day =1;
        while(!st.empty() && st.top().first <= price){
            day += st.top().second;
            st.pop();
        }
        st.push({price, day});
        ans.push_back(day);
    }
    
    
    return ans;
}

int main(){
    vector<int> a = {100, 80,60,70,60,75,80};
    vector<int> p = stock(a);
    for(auto i: p){
        cout<<i<<" ";
    }
    
    return 0;
}
