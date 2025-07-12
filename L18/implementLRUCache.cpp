#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class ListNode{
        public: 
        int key; 
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int key1, int value1){
            key = key1;
            val = value1;
        }
    };
    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);

    int cap;
    unordered_map<int, ListNode*> mpp;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    void deleteNode(ListNode* node){
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void insertAfterHead(ListNode* node){
         ListNode* currAfterHead = head->next;
         head->next = node;
         node->next = currAfterHead;
         node->prev = head;
        currAfterHead->prev = node;
    }

    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        ListNode* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            ListNode* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node); 
        }
        else {
            if(mpp.size() == cap){
                ListNode* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            ListNode* node = new ListNode(key, value);
            mpp[key] = node;
            insertAfterHead(node); 

        }
    }
};

// TC - O(1) all operations are performed in O(1)
// SC - O(capacity) 