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
  ListNode* middleNode(ListNode* head) {
    ListNode* counter = head;
    int count = 0;
    while(counter != NULL){
      ++count;
      counter = counter ->next;
    }
    for(int i = 0; i < count/2 ; ++i){
      head = head-> next;
    }
    return head;
  }
};
