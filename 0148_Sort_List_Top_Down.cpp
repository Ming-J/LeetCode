#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode *fast, *slow;
    slow = head, fast = head->next;
    while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *temp = slow->next;
    slow->next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(temp);
    return merge(l1, l2);
  }

private:
  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL, *tail = NULL, *temp = NULL;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        temp = l1;
        l1 = l1->next;
      } else {
        temp = l2;
        l2 = l2->next;
      }
      if (head == NULL) {
        head = temp;
        tail = head;
      } else {
        tail->next = temp;
        tail = tail->next;
      }
    }
    if (l1 != NULL)
      tail->next = l1;
    if (l2 != NULL)
      tail->next = l2;
    return head;
  }
};
