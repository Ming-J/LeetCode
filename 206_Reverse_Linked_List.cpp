#include <iostream>
using namcespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if(head==NULL||head->next==NULL){
	return head;
      }
      ListNode* begin=NULL;
      while(head!=NULL){
	ListNode* temp=head;
	head=head->next;
	temp->next=begin;
	begin=temp;
      }
      return begin;
    }
};
