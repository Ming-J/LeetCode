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
    int length = 0;
    for (ListNode *cur = head; cur != NULL; cur = cur->next)
      ++length;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *left = NULL, *right = NULL, *rest = NULL;
    for (int i = 1; i < length; i <<= 1) {
      ListNode *cur = dummy.next;
      rest = &dummy;
      while (cur) {
        left = cur;
        right = split(i, left);
        cur = split(i, right);
        // merge left and right and put together
        auto sorted = merge(left, right);
        rest->next = sorted.first;
        rest = sorted.second;
      }
    }
    return dummy.next;
  }

private:
  ListNode *split(int n, ListNode *li) {
    for (int i = 0; i < n - 1 && li; ++i) {
      li = li->next;
    }
    ListNode *rest = li ? li->next : NULL;
    if (li)
      li->next = NULL;
    return rest;
  }

  pair<ListNode *, ListNode *> merge(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *tail = &dummy, *temp = NULL;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        temp = l1;
        l1 = l1->next;
      } else {
        temp = l2;
        l2 = l2->next;
      }
      tail->next = temp;
      tail = tail->next;
    }
    if (l1 != NULL)
      tail->next = l1;
    if (l2 != NULL)
      tail->next = l2;
    while (tail->next)
      tail = tail->next;
    return {dummy.next, tail};
  }
};
