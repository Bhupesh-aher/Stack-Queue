
#include<bits/stdc++.h>
using namespace std;


// Appproach 1
// class MyQueue {
// public:
//     stack<int> st1;
//     stack<int> st2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         while(st1.size()){
//             st2.push(st1.top());
//             st1.pop();
//         }
//         st1.push(x);
//         while(st2.size()){
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }
    
//     int pop() {
//         int popped = st1.top();
//         st1.pop();
//         return popped;
//     }
    
//     int top() {
//         return st1.top();
//     }
    
//     bool empty() {
//         if(st1.size() == 0) return true;
//         return false;
//     }
// };

// Time Complexity:

// pop function: O(1)

// push function: O(2N) where N is current size of Stack 

// top function: O(1)

// size function: O(1)

// isEmpty function: O(1)

// Space Complexity:

// Whole Stack: O (2 * no of elements)

// This apporach is useful if no of push operations are not that high.
// if no of push operation are higher than this approach will take lot of time to push
// so in case when there is going to be lot of push operation than we will use approach 2
// in approach 2, the push operations TC will be less but TC of top and pop function will be slightly higher


// Approach 2
// This has no as such intuiton. as you dry run you will get the soltution very easily

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int popped = st2.top();
            st2.pop();
            return popped;
        }
        else {
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
            int popElement = st2.top();
            st2.pop();
            return popElement;
        }
    }
    
    int top() {
        if(!st2.empty()){
            return st2.top();
        }
        else {
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        if(st1.size() == 0 && st2.size() == 0) return true;
        return false;
    }
};


// Time Complexity:

// pop function: O(1) and sometimes for s1 to s2 taking O(N)

// push function: O(1) where N is current size of queue

// top function: O(1) and sometimes for s1 to s2 taking O(N)

// size function: O(1)

// isEmpty function: O(1)

// Space Complexity:

// Whole Queue: O(2 * no of elements)

int main(){
    MyQueue q;
    q.push(4);
    q.push(9);
    q.push(2);
    q.push(5);
    cout << "Top element of queue is " << q.top() << endl;
    cout << "Delete element is " << q.pop() << endl;
    cout << "Top element of queue is " << q.top() << endl;
    cout << q.empty();
}