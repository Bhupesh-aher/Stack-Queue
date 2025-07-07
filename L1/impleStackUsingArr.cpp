#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int size;
    int * arr;

    public: 
    Stack(){
        top = -1;
        size = 10;
        arr = new int[size];
    }

void push(int x){
    if(top >= 10) cout << "size is full";
    top = top + 1;
    arr[top] = x;
}

int pop(){
    if(top == -1){
         cout << "no elements to pop";
         return -1;
    }
    int x = arr[top];
    top = top - 1;
    return x;
}

int Top(){
    return arr[top];
}

int Size(){
    return top + 1;
}

};

// Time Complexity:

// pop function: O(1)

// push function: O(1)

// top function: O(1)

// size function: O(1)

// Space Complexity:

// Whole Stack: O(n)

int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}

