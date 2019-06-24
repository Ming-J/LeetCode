/*
  Largetst Permutation
  switch with something that is largest smaller than you

  1 9 7 8  9

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &A) {
    int left = A.size() - 2, right = A.size() - 1;
    //Finding the First non decresement element;
    while (left >= 0 && A[left] <= A[right])
      left--, right--;
    if (left == -1)
      return A;  
    right = A.size() - 1;
    //Finding the largest element that is smaller than left;
    while (A[left] <= A[right])
      --right;
    //In the case of there are multiple right, we want the most left one {3,1,1,3}
    while (A[right] == A[right - 1])
      --right;
    swap(A[left], A[right]);
    return A;
  }
};
//Second part can use binary search to reduce time complexity
int main() {
  vector<int> A = {1, 9, 4, 6, 7};
  A = {3, 1, 1, 3};
  Solution s;
  for (auto n : s.prevPermOpt1(A)) {
    cout << n << ' ';
  }
}
