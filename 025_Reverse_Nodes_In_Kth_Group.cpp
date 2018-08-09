#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    ListNode* prevHead = dummy;
    dummy->next = head;
    ListNode* partialTail = kthNode(prevHead->next, k);
    while(partialTail != NULL){
      ListNode* oldTail = prevHead->next;
      prevHead->next = reverseList(prevHead->next,partialTail);
      prevHead = oldTail;
      partialTail = kthNode(prevHead->next,k);
    }
    return dummy->next;
  }
  
private:
  ListNode* kthNode(ListNode* head, int k){
    for(int i = 1; head != NULL && i < k; ++i){
      head = head -> next;
    }
    return head;
  }
  
  ListNode* reverseList(ListNode* head, ListNode* tail){
    ListNode* revHead = tail->next;
    ListNode* revTail = revHead;
    while(head != tail){
      ListNode* curNext = head -> next;
      head -> next = revTail;
      revTail = head;
      head = curNext;
    }
    tail -> next = revTail;
    return tail;
  }
};
