//Largest rectangle in a histogram
#include<bits/stdc++.h>
using namespace std;

int max_area(vector<int> a){
    int n = a.size();
    int area = 0 , i=0;
    
    stack<int> st;
    a.push_back(0);
    while(i<n){
        while(!st.empty() && a[st.top()] > a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if(!st.empty()){
                area = max(area, h*i);
            }
            else{
                int len = i- st.top() - 1;
                area = max(area, h*len);
            }
        }
        st.push(i);
        i++;
    }
}

int main(){
    vector<int> a = {4,12,5,4,1,6};
    cout<<max_area(a);
    return 0;
}
