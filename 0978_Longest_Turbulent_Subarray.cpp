#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxTurbulenceSize(vector<int> &A) {
        if (A.size() < 2)
            return A.size();
        int ans = 0, sub = 0;
        for (size_t i = 1; i < A.size(); ++i) {
            ans *= -1;
            if (A[i - 1] > A[i])
                ans = (ans > 0) ? ans + 1 : 2;
            else if (A[i - 1] < A[i])
                ans = (ans < 0) ? ans - 1 : -2;
            else
                ans = 1;
            sub = max(sub, abs(ans));
        }
        return sub;
    }
};

int main() {
    vector<int> input = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    Solution t;
    cout << t.maxTurbulenceSize(input) << endl;
};
