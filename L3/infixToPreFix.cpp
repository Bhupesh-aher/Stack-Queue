#include<bits/stdc++.h>
using namespace std;


// Function to return which operator has more priority over other
int priority(char c){
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPreFix(string s){
    string ans = "";
    stack<char> st;

    for(int i = 0; i<s.length(); i++){
        // if operand just push it in stack without thinking anthing
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }

        // openning bracket just push this as well
        else if(s[i] == '('){
            st.push(s[i]);
        }

        // closing bracket in this case take out all ele from stack one by one add to ans till you get opening bracket
        // at the end pop out the opening bracket as well
        else if(s[i] == ')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        // adding operators
        // if current operator has less priority than opertor who is at top() of stack than just add stack top() till 
        // current operator has more priority than stack top
        else {
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    // anything left in stack just add it in ans
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end()); // step 3
    return ans;
}

// TC - O(4N) SC - O(N)

int main(){
    string s = "(A+B)*C-D+F";

    reverse(s.begin(), s.end()); // step 1

    for(int i = 0; i<s.length(); i++){    // step 1.1 (bracket reverse step)
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    cout << "Infix expression " << s << endl;
    cout << "After conversion Infix to PreFix expression " << infixToPreFix(s) << endl;
    
}


// Infix expression (d-c)*(q+p)
// After conversion Infix to PreFix expression *+pq-cd
