#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int minKBitFlips(vector<int> &A, int K) {
        int flip = 0;
        queue<int> indexs;
        for (size_t i = 0; i < A.size(); ++i) {
            int pivot = indexs.size() % 2 == 0 ? A[i] : 1 - A[i];
            if (pivot == 0) {
                flip++;
                indexs.push(i + K - 1);
            }
            if (!indexs.empty() && indexs.front() == i)
                indexs.pop();
        }
        return indexs.empty() ? flip : -1;
    }
};