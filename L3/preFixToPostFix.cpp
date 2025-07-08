#include<bits/stdc++.h>
using namespace std;


string preFixToPostFix(string s){
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
            string conv = t1 + t2 + s[i];         // top1  top2  operator
            st.push(conv);
        }
    }
    return st.top();
}

// TC - O(N) + (N1 + N2) SC - O(N)

int main(){
    string s = "/-AB*+DEF";

    cout << "PreFix expression " << s << endl;
    cout << "After conversion PreFix to PostFix expression " << preFixToPostFix(s) << endl;
    
}
