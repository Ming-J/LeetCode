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
  ListNode* rotateRight(ListNode* head, int k) {
    int length=countlink(head);
    if(length==1||length==0){
      return head;
    }
    k%=length;
    if(k==0){
      return head;
    }
    k=length-k;
    ListNode* pre=head;
    ListNode* begin=head;
    for(size_t i=0;i<k;i++){
      pre=begin;
      begin=begin->next;
    }
    if(k==length-1){
      begin->next=head;
    }else{
      ListNode* preTail=begin;
      while(preTail->next!=NULL){
	preTail=preTail->next;
      }
      preTail->next=head;
    }
    pre->next=NULL;
    return begin;
  }

  int countlink(ListNode* head){
    int count=0;
    while(head!=NULL){
      count++;
      head=head->next;
    }
    return count;
  }
};
