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
    ListNode* oddEvenList(ListNode* head) {
      if(head==NULL||head->next==NULL||head->next->next==NULL){
	return head;
      }
      ListNode* oddTail=head, evenTail=head->next, currentIndex=head->next->next;
      int n=3;
      while(currentIndex!=NULL){
	ListNode* temp=currentIndex->next;
	if(n%2==1){
	  currentIndex->next=oddTail->next;
	  oddTail->next=currentIndex;
	  oddTail=currentIndex;
	}else{
	  evenTail->next=currentIndex;
	  evenTail=currentIndex;
	}
	n++;
	currentIndex=temp;
      }
      evenTail->next=NULL;
      return head;
    }
};
