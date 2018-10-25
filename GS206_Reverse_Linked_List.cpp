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
  ListNode* reverseList(ListNode* head) {
    if(head == NULL) return head;
    //ListNode* cur = head;
    ListNode* newhead = NULL;
    while(head != NULL){
      ListNode* cur = head;
      head = head->next;
      cur->next = newhead;
      newhead = cur;
    }
    return newhead;
  }
};
