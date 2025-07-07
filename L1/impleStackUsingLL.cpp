#include<bits/stdc++.h>
using namespace std;

struct stackNode{
    int data;
    stackNode* next;
    
    stackNode(int data1){
        data = data1;
        next = nullptr;
    }
};

struct Stack
{
    stackNode *top;
    int size = 0;
    Stack(){
        top = nullptr;
        size = 0;
    }

    void push(int x){
        stackNode* temp = new stackNode(x);
        temp->next = top;
        top = temp;
        size ++;
    }

    int pop(){
        if(top == NULL) return -1;
        int topData = top->data;
        stackNode* temp = top;
        top = top->next;
        delete temp;
        size --;
        return topData;
    }

    int Size(){
        return size;
    }

    int Top(){
        if(top == NULL) return -1;
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};


// Time Complexity:

// pop function: O(1)

// push function: O(1)

// top function: O(1)

// size function: O(1)

// isEmpty function: O(1)

// Space Complexity:

// Whole stack: O(no of elements)

int main(){
  Stack s;
  s.push(10);
  cout << "Element popped: " << s.pop() << "\n";
  cout << "Stack size: " << s.Size() << "\n";
  cout <<"Stack empty or not? "<<s.isEmpty()<<"\n";
  cout << "stack's top element: " << s.Top() << "\n";
  return 0;
}
