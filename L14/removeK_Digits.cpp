#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    for(int i  = 0; i<num.length(); i++){
        while(!st.empty() && k > 0 && (st.top() - '0') > ( num[i] - '0')){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while(k > 0) {
        st.pop();
        k --;
    }
    if(st.empty()) return "0";
    string res = "";
    while(!st.empty()){               // O(N)
        res += st.top();
        st.pop();
    } 

    while(res.length() != 0 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());            // O(N)
    if(res.length() == 0) return "0";
    return res;
}

// TC - O(3N) + O(K) 
// SC - O(N)

int main(){
    string s = "1432219";
    int k = 3;
    cout << removeKdigits(s, k);
    
}