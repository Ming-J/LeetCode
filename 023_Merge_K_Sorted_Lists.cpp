
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode* ans = NULL;
      auto func = [&ans,this](ListNode* i){ ans = mergeTwoLists(ans,i);};
      for_each(lists.begin(),lists.end(),func);
      return ans;
    }
  
private:
  ListNode* mergeTwoLists(ListNode* le, ListNode* ri){
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    while(le != NULL && ri != NULL){
      if(le -> val < ri -> val){
	tail -> next = le;
	le = le -> next;
      }else{
	tail -> next = ri;
	ri = ri -> next;
      }
      tail = tail -> next;
    }
    tail -> next = (le!=NULL)? le : ri;
    return head->next;
  }
};
