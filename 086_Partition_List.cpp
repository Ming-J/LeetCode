#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* cur = head;
    ListNode* smallThanX = NULL;
    ListNode* smallThanXTail = NULL;
    ListNode* greaterThanX = NULL;
    ListNode* greaterThanXTail = NULL;
    while(cur != NULL){
      if(cur->val < x){
	if(!smallThanX && !smallThanXTail){
	  smallThanX = smallThanXTail = cur;
	}else{
	  smallThanXTail->next = cur;
	  smallThanXTail = cur;
	}
	cur = cur ->next;
	smallThanXTail->next = NULL;
      }else{
	if(!greaterThanX && !greaterThanXTail){
	  greaterThanX = cur;
	  greaterThanXTail = cur;
	}else{
	  greaterThanXTail -> next = cur;
	  greaterThanXTail = cur;
	}
	cur = cur->next;
	greaterThanXTail ->next = NULL;
      }
    }
    if(smallThanXTail) smallThanXTail -> next = greaterThanX? greaterThanX:NULL;
    return smallThanX?smallThanX:greaterThanX;
  }
};
