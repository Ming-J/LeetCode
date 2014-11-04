// Definition for singly-linked list.
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 */
#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      // use for carry
      int carry=0;
      //use for remander
      int rem=0;
      //create a linked list with dummy head
      ListNode sum(0);
      ListNode *pre=&sum;
      while(l1!=NULL||l2!=NULL||carry>0){
	//check to see if there is an carry, either 1 or 0
	rem=carry;
	//adding value to rem
	if(l1!=NULL){
	  rem=rem+l1->val;
	  l1=l1->next;
	}
	//adding value to rem
	if(l2!=NULL){
	  rem=rem+l2->val;
	  l2=l2->next;
	}
	//check to see the value of carry
	carry=rem/10;
	//create a linked listed with the new remander value
	pre->next=new ListNode(rem%10);
	pre=pre->next;
      }
      pre->next=NULL;
      //return with out the linked list with out the dummy head
      return sum.next;
    }
};

int main(){
  cout<<"Hello worlds!"<<endl;
}
