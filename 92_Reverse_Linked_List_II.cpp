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
      if(head==NULL||m==n){
	return head;
      }
      ListNode* first=head;
      ListNode* beforeM=head;
      //Traverse to listNode M
      for(int i=1;i<m;i++){
	if(i==m-1){
	  beforeM=head;
	}
	head=head->next;
      }
      int difference=n-m;
      ListNode* reverseBegin=head;
      ListNode* reverseEnd=head;
      ListNode* secondPart=head->next;
      while(difference>0){
	ListNode* addToReverse=secondPart;
	secondPart=secondPart->next;
	addToReverse->next=reverseEnd;
	reverseEnd=addToReverse;
	difference--;
      }
      reverseBegin->next=secondPart;
      if(beforeM==first&&beforeM==reverseBegin){
	return reverseEnd;
      }else{
	beforeM->next=reverseEnd;
	return first;
      }
    }
};
