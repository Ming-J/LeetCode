#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int largestSumAfterKNegations(vector<int> &A, int K) {
    //make_heap(A.begin(), A.end(), greater<int>());
    priority_queue<int,vector<int>,greater<>> pq(A.begin(),A.end());
    for (int i = 0; i < K; ++i) {
      int temp = pq.top() * -1;
      pq.pop();
      pq.push(temp);
    }
    int sum = 0;
    while (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
    for (auto a : A) {
      cout << a << endl;
    }
    return sum;
  }
};

int main() {
  vector<int> A = {3, 4, 56, 768, 85, 1};
  Solution t;
  t.largestSumAfterKNegations(A, 5);
}
