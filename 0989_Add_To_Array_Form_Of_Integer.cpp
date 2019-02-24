#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> ans(A.rbegin(), A.rend());
        int carry = 0;
        int j = 0;
        for (size_t j = 0; K > 0 || carry == 1; ++j, K /= 10) {
            if (j >= ans.size())
                ans.push_back(0);
            ans[j] += (K % 10) + carry;
            carry = ans[j] >= 10 ? 1 : 0;
            ans[j] %= 10;
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};