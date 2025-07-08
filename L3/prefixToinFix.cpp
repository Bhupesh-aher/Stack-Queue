#include<bits/stdc++.h>
using namespace std;


string preFixToinFix(string s){
    stack<string> st;

    for(int i = s.length() - 1; i>=0; i--){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conv = '(' + t1 + s[i] + t2 + ')';   // top1  operator  top2
            st.push(conv);
        }
    }
    return st.top();
}

// TC - O(N) + (N1 + N2) SC - O(N)

int main(){
    string s = "*+PQ-MN";

    cout << "PreFix expression " << s << endl;
    cout << "After conversion PreFix to Infix expression " << preFixToinFix(s) << endl;
    
}
