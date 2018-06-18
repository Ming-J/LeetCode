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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    for(int i = 1; i < m; ++i){
      dummy = dummy->next;
    }
    ListNode* newhead = NULL;
    ListNode* newtail = dummy->next;;
    for(int i = m; i <= n; ++i){
      ListNode* temp = dummy->next;
      dummy->next = dummy->next->next;
      temp->next = newhead;
      newhead = temp;
    }
    ListNode* temp = dummy->next;
    dummy->next = newhead;
    newtail->next = temp;
    return (m!=1)?head:newhead;;
  }
};
