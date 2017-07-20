#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* removeElements(ListNode* head, int val){
    if(head==NULL){
      return head;
    }
    ListNode* temp=head;
    while(head->val==val){
      if(head->next==NULL){
    	return NULL;
      }else{
    	head=head->next;
      }
    }
    ListNode* previous=head;
    temp=head->next;
      while(temp!=NULL){
	if(temp->val==val){
	  if(temp->next==NULL){
	    previous->next=NULL;
	  }else{
	    previous->next=temp->next;
	  }
	  temp=temp->next;
	}else{
	  temp=temp->next;
	  previous=previous->next;
	}
      }
      return head;
  }
};


int main(){
  return 0;
}
