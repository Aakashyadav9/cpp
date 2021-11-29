//Redundant Parenthesis
#include<bits/stdc++.h>
using namespace std;

int redundent(string s){
    int ans = false;
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '('){
                ans = true;
            }
            while(st.top() == '+' || st.top() == '-' ||st.top() == '*' ||st.top() == '/' ){
                st.pop();
            }
            st.pop();
        }
    }
    return ans;
}

int main(){
    string s = "(a+(a+b))";
    cout<<redundent(s);
    return 0;
}
