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
  ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head -> next == NULL){
      return head;
    }
    ListNode* temphead = duplicate(head);
    while(temphead!=NULL && head != temphead){
      head = temphead;
      temphead = duplicate(head);
    }
    ListNode* cur = temphead;
    while(cur != NULL && cur->next!=NULL){
      ListNode* next = duplicate(cur->next);
      if(cur->next != next){
	cur->next = next;
      }else{
	cur = cur->next;
      }
    }
    return temphead;
  }
private:
  ListNode* duplicate(ListNode* cur){
    if(cur->next == NULL || cur->val != cur->next->val) return cur;
    while(cur!=NULL&&cur->next!=NULL){
      if(cur->val != cur->next->val) return cur->next;
      cur = cur->next;
    }
    return cur->next;
  }
};
