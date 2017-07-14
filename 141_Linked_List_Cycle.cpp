/*==============================================================
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Logic: We could use two pointer traveling at different speed to see if
a linked list has a cycle. One pointer traving to the next linked list
while the other travel at two linked list at the time. If it has a
cycle the two pointer will eventually be pointing to the same
place. If it's not a cycle the faster pointer will just reach to the
end.

space complexity: 2 pointer
time complexity: when no cycle it will be N/2 

 ===============================================================*/
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  bool hasCycle(ListNode *head){
    if(head==NULL||head->next==NULL||head->next->next==NULL){
      return false;
    }
    ListNode *one=head;
    ListNode *two=head;
    while(two->next!=NULL&&two->next->next!=NULL){
	one=one->next;
	two=two->next->next;
	if(one==two){
	  return true;
	}
   }
    return false;
  }
};

int main(){
  Solution test;
  struct ListNode first(3);
  test.hasCycle(&first);
}
