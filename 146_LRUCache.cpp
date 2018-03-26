#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
Design and implement a data structure for Least Recently Used (LRU)
cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the
key exists in the cache, otherwise return -1.  

put(key, value) - Set
or insert the value if the key is not already present. When the cache
reached its capacity, it should invalidate the least recently used
item before inserting a new item.
*/
struct DNode{
  int key;
  int val;
  DNode* next;
  DNode* prev;
  DNode(int k, int n){
    key = k;
    val = n;
    next = NULL;
    prev = NULL;
  }
};


class LRUCache {
public:
    LRUCache(int capacity) {
      cap = capacity;
      head = tail = NULL;
    }
    
    int get(int key) {
      if(contain.find(key) != contain.end()){
        DNode* removed = remove(contain[key]);    
        addToHead(removed);
        return removed->val;
      }
      return -1;
    }
    
    void put(int key, int value) {
      if(contain.find(key) != contain.end()){
        DNode* removed = remove(contain[key]);
        removed->val = value;
        addToHead(removed);
      }else{
        DNode* newNode = new DNode(key, value);   
        contain[key] = newNode;
        addToHead(newNode);
        if(contain.size() > cap){
         DNode* removed = remove(tail);
         contain.erase(removed->key);
        }
      }            
    }
  
private:
  unsigned int cap;
  // key : linlist node 
  unordered_map<int,DNode*> contain;
  DNode *head;
  DNode *tail;
  //remove function
  DNode* remove(DNode* cur){
    if(head == tail){
      head = tail = NULL;
    }else if( cur == head ){
     head = cur -> next;
     head -> prev = NULL;
   }else if( cur == tail){
     tail = cur -> prev;
     tail -> next = NULL;
   }else{
     DNode* before = cur->prev;  
     DNode* after =  cur-> next;
     before -> next = after;
     after -> prev = before;
   }
   return cur;
  }
  // moving a node to the head
  void addToHead(DNode *node){
    if(head == NULL && tail == NULL){
      head = node;
      tail = node;
    }
     //moving the head to the front
     node -> next = head;
     node -> prev = NULL;
     head -> prev = node;
     head = node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
void printListFromHead(DNode* head){
  while(head != NULL){
    cout<<head->val<<"->";
    head = head -> next;
  }
}

void printListFromBack(DNode* tail){
  while(tail != NULL){
    cout<<tail->val<<"->";
    tail = tail -> prev;
  }
}

// To execute C++, please define "
/*
["LRUCache","put","put","get","put","put","get"]
[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
*/
int main(){
  LRUCache obj(2);
  obj.put(2,1);
  obj.put(2,2);
  cout<<obj.get(2)<<endl;
  obj.put(1,1);
  obj.put(4,1);
  cout<<obj.get(2)<<endl;
  //cout<<obj.get(3)<<endl;
  //obj.put(30,3);
  //obj.put(10,1);
  //int param_1 = obj.get(30);
  //int param_2 = obj.get(10);
  //cout<<param_1<<' '<<param_2<<endl;
  
//   DNode* one = new DNode(1,1);
//   DNode* two = new DNode(2,2);
//   DNode* three = new DNode(3,3);
//   one->next = two;
//   two->next = three;
//   three->prev = two;
//   two->prev = one;
  
//   printListFromHead(one);
//   cout<<endl;
//   printListFromBack(three);
}
