#include <iostream>
using namespace std;
/*
  Using Sliding Window to manage the front and back of the window.
*/

class Solution {
public:
  int totalFruit(vector<int> &tree) {
    int first = tree.front(), first_front = 0, first_back = 0;
    int second = -1, second_front = 0, second_back = 0;
    int length = 1;
    for (size_t i = 1; i < tree.size(); ++i) {
      // When the current fruit matches our first type, we update the first
      // window
      if (tree[i] == first) {
        first_back = i;
      } else if (second == -1) {
        // initializing the second type of fruit
        second = tree[i];
        second_front = second_back = i;
      } else if (tree[i] == second) {
        // matches our second type of fruit, we update the second window
        second_back = i;
      } else {
        /* we have reach the third type of fruit, so we caculate the current
         * length(Note: we have to see fruit with largest back index), Update
         * the first type of fruit which will be the fruit before current fruit
         * and find the front, update current fruit to the second type of fruit
         */
        length = max(length, max(second_back, first_back) - first_front + 1);
        first_front = first == tree[i - 1] ? second_back + 1 : first_back + 1;
        first_back = i - 1;
        first = tree[first_front];
        second = tree[i];
        second_front = second_back = i;
      }
    }
    return max(length, max(second_back, first_back) - first_front + 1);
  }
};
