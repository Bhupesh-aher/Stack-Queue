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

struct Queue
{
    stackNode *top;
    stackNode* start;
    stackNode* end;
    int size = 0;
    Queue(){
        top = nullptr;
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void push(int x){
        stackNode* temp = new stackNode(x);
        if(start == NULL){
            start = temp;
            end = temp;
        }
        else {
            end->next = temp;
            end = temp;
        }
        size ++;
    }

    void pop(){
        if(start == NULL) cout << "nothing to delete";
        stackNode* temp = start;
        start = start->next;
        delete temp;
        size --;
    }
    
    int Top(){
        if(start == NULL) {
            cout << "no elemnents";
            return -1;
        } 
        return start->data;
    }

    int Size(){
        return size;
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

// Whole Queue: O(no of elements)

int main(){
  
    Queue Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.pop();
    cout<<"The size of the Queue is "<<Q.Size()<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Top()<<endl;
    return 0;
}
