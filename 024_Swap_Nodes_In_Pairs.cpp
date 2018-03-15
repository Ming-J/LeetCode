/*===============================================================================
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the
values in the list, only nodes itself can be changed.


For this type of question: we will think about the edge case which is when
-0 or 1 node left: we will simply return the same pointer that was given.

After we took care of the edge cases, we will declear a variable to
store the new head pointer, as instructed by the question. As we know
after the swap we will always return the second node. so we store the
second node and return at the end.

Then we will have our while loop, the condition of the while loop will
be if there are two more loop to swap. If not, there is nothing to
swap we simple just return the head pointer. There are three cases of swaping.

1.when only two nodes are left:
2->3->NULL   we will store 3->2, and 2->NULL

2.When three nodes are left:
2->3->4->NULL we will store 4 as temp, 3->2, 2->temp

3.When more than three nodes are left:
2->3->4->5->....  we will store 4 and 5 as temp, 3->2, 2->5, set head pointer as 4

 ================================================================================*/
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* swapPairs(ListNode* head){

    if(head==NULL||head->next==NULL){
      return head;
    }

    ListNode* begin=head->next;

    while(head!=NULL&&head->next!=NULL){
      if(head->next->next==NULL){
	head->next->next=head;
	head->next=NULL;	
      }else if(head->next->next->next==NULL){
	ListNode *temp=head->next->next;
	head->next->next=head;
	head->next=temp;
	head=temp;
      }else{
	ListNode *temp=head->next->next;  //store the node need to connect to
	ListNode *temp2=head->next->next->next;
	head->next->next=head;
	head->next=temp2;
	head=temp;
      }
    }
    return begin;
  }
};

int main(){
  ListNode first=ListNode(1);
  ListNode second=ListNode(2);
  ListNode third=ListNode(3);
  ListNode four=ListNode(4);
  first.next=&second;
  second.next=&third;
  third.next=&four;
  Solution test;
  test.swapPairs(&first);
  return 0;
}
