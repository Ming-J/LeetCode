#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //Linked list null check
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    //going though the l1 and l2, add up there value, with a carry
    int carry = 0;
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    while(l1!=NULL||l2!=NULL||carry>0){
      int val1 = (l1!=NULL)?l1->val:0;
      int val2 = (l2!=NULL)?l2->val:0;
      int sum = val1 + val2 + carry;
      carry = sum / 10;
      int reminder = sum % 10;
      ListNode* newVal = new ListNode(reminder);
      tail->next = newVal;
      tail = newVal;
      if(l1!=NULL) l1 = l1->next;
      if(l2!=NULL) l2 = l2->next;
    }
    return dummy->next;
  }
};
