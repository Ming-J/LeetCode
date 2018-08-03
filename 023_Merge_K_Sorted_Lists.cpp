
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      
    }

private:
  ListNode* mergeTwoLists(ListNode* le, ListNode* ri){
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    while(le != NULL && ri != NULL){
      if(le->val < ri-> val){
	tail -> next = le;
	le = le -> next;
      }else{
	tail -> next = ri;
	ri = ri -> next;
      }
      tail = tail -> next;
    }
    tail -> next = (le!=NULL)? le : ri;
    else  tail->next;
  }
};
