#include <iostream>
using namespace std;

/*Use two pointer to get the gap between the end and the one before to
  be deleted. So we iterating from 0 to n. If the end are NULL that
  means we are deleting the head, so simply return the second node.

  Once we set the correct gap between the two pointer, we iterate the
  end node to the end and just have beforeToDelete skip over the next
  one.

  Constant Space with liner complexity
*/

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* end=head;
      for(int i=0;i<n;i++){
	end=end->next;
      }
      if(end==NULL){
	return head->next;
      }
      ListNode* beforeToDelete=head;
      while(end->next!=NULL){
	end=end->next;
	beforeToDelete=beforeToDelete->next;
      }
      beforeToDelete->next=beforeToDelete->next->next;
      return head;
    }
};
