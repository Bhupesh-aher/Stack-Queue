#include<bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    int key;
    int cnt;
    Node* next;
    Node* prev;
    Node(int key1, int value){
        key = key1;
        val = value;
        cnt = 1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
        size++;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    } 
};


class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int cap;
    int minFreq;
    int currSize;
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->insertAfterHead(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            updateFreqListMap(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else {
            if(currSize == cap){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }
            currSize++;

            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->insertAfterHead(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

