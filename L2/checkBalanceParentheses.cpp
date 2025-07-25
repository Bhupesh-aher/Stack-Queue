#include<bits/stdc++.h>
using namespace std;


bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i<s.length(); i++){
        if(s[i] ==  '(' || s[i] ==  '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else {
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if(s[i] == ')' && ch == '(' || s[i] == ']' && ch == '[' || s[i] == '}' && ch == '{'){
                continue;
            }
            else return false;
        }
    }
    return st.empty();
}
// TC - O(N) SC - O(N) 



int main(){
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}