#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &A) {
    int total = accumulate(A.begin(), A.end(), 0);
    cout << total << endl;
    vector<int> front(A.size()), back(A.size());
    partial_sum(A.begin(), A.end(), front.begin());
    partial_sum(A.rbegin(), A.rend(), back.rbegin());
    for (auto i : front)
      cout << i << ' ';
    cout << endl;
    for (auto i : back)
      cout << i << ' ';
    cout << endl;
    if (total % 3 != 0)
      return false;
    int partSum = total / 3, sum = 0;
    auto front_it = find(front.begin(), front.end(), partSum);
    cout << (front_it - front.begin()) << endl;
    auto back_it = find(back.rbegin(), back.rend(), partSum);
    cout << *back_it << (back.rend() - back_it) << ' '
         << distance(back.rbegin(), back_it) << ' '
         << (A.size() - 1 - (back_it - back.rbegin())) << endl;
    return front_it != front.end() && back_it != back.rend() &&
           (front_it - front.begin()) <
               (A.size() - 1 - (back_it - back.rbegin()));
  }
};

int main() {
  vector<int> input = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
  Solution t;
  if (t.canThreePartsEqualSum(input)) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
}
