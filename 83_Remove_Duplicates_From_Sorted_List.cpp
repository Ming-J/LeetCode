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
    if(head==NULL){
      return NULL;
    }
    ListNode* sl=head;
    ListNode* fa=head;
    while(sl->next!=NULL){
      int slval=sl->val;
      int faval=fa->val;
      if(slval==faval){
	while(fa->next!=NULL&&slval==faval){
	  fa=fa->next;
	  faval=fa->val;
	}
	if(fa->next!=NULL||slval!=faval){
	  sl->next=fa;
	}else{
	  sl->next=NULL;
	}
      }else{
	sl=sl->next;
      }
    }
    return head;
  }
};
