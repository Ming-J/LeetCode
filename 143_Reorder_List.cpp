#include <iostream>
using namespace std;
/*
  Time Complexity is O(n(n-1)/2) Since I am finding the tail every
  single time after I moved the end node. So The complexity will be
  bad.  A better solution will be find the mid point of the list,
  reverse the second part of the list and zigzac with the first half.
*/
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode* head) {
    if(head==NULL){return;}
      ListNode* tail=head;
      ListNode* st=head;
      int count=1;
      while(tail->next!=NULL){
	tail=tail->next;
	count++;
      }
      if(count==1||count==2){return;}
      count/=2;
      while(count+1>=0){  //taking care of the list with odd number of node
	ListNode* temp=head->next;
	head->next=tail;
	tail->next=temp;
	tail=getLast(temp,tail);
	head=temp;
	count--;
      }
      head->next=NULL;
      while(st!=NULL){
	cout<<st->val<<endl;
	st=st->next;
      }
    }

  ListNode* getLast(ListNode* head, ListNode* end){
    while(head->next!=end){
      head=head->next;
    }
    return head;
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
