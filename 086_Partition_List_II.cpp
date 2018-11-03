#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* partition(ListNode*head,int x){
    if(head == NULL) return NULL;
    ListNode* smallHead = new ListNode(-1);
    ListNode* smallTail = smallHead;
    ListNode* bigHead = new ListNode(-1);
    ListNode* bigTail = bigHead;
    while(head != NULL){
      ListNode* cur = head;
      head = head->next;
      cur->next = NULL;
      if(cur->val < x){
	smallTail->next = cur;
	smallTail = cur;
      }else{
	bigTail->next = cur;
	bigTail = cur;
      }
    }
    smallTail->next = bigHead->next;
    return smallHead->next;
  }  
};
