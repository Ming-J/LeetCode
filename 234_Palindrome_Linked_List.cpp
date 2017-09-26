#include <iostream>
using namespace std;

//* Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
      string palin="";
      while(head!=NULL){
	palin+=head->val;
	head=head->next;
      }
      int ba=palin.size()-1;
      for(int i=0;i<palin.size();i++){
	if(palin[i]!=palin[ba]){
	  return false;
	}
	ba--;
      }
      return true;
    }
};
