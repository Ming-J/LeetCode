// Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA==NULL||headB==NULL){
	return NULL;
      }
      int countA=0;
      int countB=0;
      ListNode* traversalA=getToTheEnd(headA,countA);
      ListNode* traversalB=getToTheEnd(headB,countB);
      if(traversalA!=traversalB){
	return NULL;
      }else{
	int difference=countA-countB;
	traversalA=headA;
	traversalB=headB;
	if(difference>0){
	  for(int i=0;i<difference;i++){
	    traversalA=traversalA->next;
	  }
	}else{
	  difference*=-1;
	  for(int i=0;i<difference;i++){
	    traversalB=traversalB->next;
	  }
	}
	while(traversalA->next!=NULL&&traversalB->next!=NULL){
	  if(traversalA==traversalB){
	    return traversalA;
	  }else{
	    traversalA=traversalA->next;
	    traversalB=traversalB->next;
	  } 
	}
	return traversalA;
      }     
    }
  ListNode* getToTheEnd(ListNode* head, int& count){
    while(head->next!=NULL){
      head=head->next;
      count++;
    }
    return head;
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
