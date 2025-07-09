#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

// TC - O(1) all operations
// SC - O(2 * N) we are storing pair



class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            min = val;
            st.push(val);
        }
        else {
            if(val >= min) st.push(val);
            else {
                st.push(2LL * val - min);
                min = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < min) {
            min = 2LL * min - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(min <= x) return x;
        else return min;
    }
    
    int getMin() {
        return min;
    }
};
// TC - O(1) all operations
// SC - O(N) 

int main(){
    MinStack st;
    st.push(12);
    st.push(15);
    st.push(10);
    cout << "Minimum element in stack till this point " << st.getMin() << endl;;
    st.pop();
    cout << "Top element is " << st.top() << endl;;
    cout << "Minimum element in stack till this point " << st.getMin() << endl;
    
}