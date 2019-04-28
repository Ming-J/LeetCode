#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> ans;
    stack<pair<int, int>> st;
    int count = 0;
    ans.resize(10000);
    for (auto p = make_pair(head, 0); p.first != NULL;
         ++count, p.first = p.first->next, ++p.second) {
      while (!st.empty() && st.top().first < p.first->val) {
        int smaller_i = st.top().second;
        ans[smaller_i] = p.first->val;
        st.pop();
      }
      st.push(make_pair(p.first->val, p.second));
    }
    ans.resize(count);
    return ans;
  }
};
