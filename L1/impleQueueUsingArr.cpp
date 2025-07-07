#include<bits/stdc++.h>
using namespace std;

class Queue{
    int start;
    int end;
    int Currsize;
    int * arr;
    int size;

    public: 
    Queue(){
        start = -1;
        end = -1;
        Currsize = 0;
        size = 10;
        arr = new int[size];
    }

    void push(int x){
        if(Currsize == size){
             cout << "Queue is full" << endl;
             exit(1);
        }
        if(Currsize == 0){
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % size;
        }
        arr[end] = x;
        Currsize ++;
    }

    int pop(){
        if(Currsize == 0) {
            cout << "nothng to delete";
            exit(1);
        }
        int popped = arr[start];
        if(Currsize == 1){
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % size;
        }
        Currsize --;
        return popped;
    }

    int top(){
        if(Currsize == 0) {
            cout << "don't have any element";
            exit(1);
        }
        return arr[start];
    }

    int Size(){
        return Currsize;
    }

};

// Time Complexity:

// pop function: O(1)

// push function: O(1)

// top function: O(1)

// size function: O(1)

// Space Complexity:

// Whole Queue: O(n)

int main() {
  Queue q;
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.Size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.Size() << endl;

  return 0;
}

