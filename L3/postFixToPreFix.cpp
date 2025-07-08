#include<bits/stdc++.h>
using namespace std;


string postFixToPreFix(string s){
    stack<string> st;

    for(int i = 0; i<s.length(); i++){

        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conv = s[i] + t2 + t1;         // operator top2  top1 
            st.push(conv);
        }
    }
    return st.top();
}

// TC - O(N) + (N1 + N2) SC - O(N)

int main(){
    string s = "AB-DE+F*/";

    cout << "PostFix expression " << s << endl;
    cout << "After conversion PostFix to PreFix expression " << postFixToPreFix(s) << endl;
    
}
