#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int popped = q.front();
        q.pop();
        return popped;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size() == 0) return true;
        return false;
    }
};

// Time Complexity:

// pop function: O(1)

// push function: O(N) where N is current size of queue

// top function: O(1)

// size function: O(1)

// isEmpty function: O(1)

// Space Complexity:

// Whole Queue: O(no of elements)


int main(){
    MyStack st;
    st.push(4);
    st.push(9);
    st.push(2);
    st.push(5);
    cout << "Top element of stack is " << st.top() << endl;
    cout << "Delete element is " << st.pop() << endl;
    cout << "Top element of stack is " << st.top() << endl;
    cout << st.empty();
    
}