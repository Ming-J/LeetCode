#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  public:
    int subarraysDivByK(vector<int> &A, int K) {
        vector<int> dp(K + 1);
        int result = 0;
        for (int i = 0, sum = 0; i < A.size(); ++i) {
            sum += A[i];
            sum %= K;
            if (sum < 0)
                sum += K;
            ++dp[sum];
        }
        for_each(dp.begin(), dp.end(),
                 [&](int x) { result += x * (x - 1) / 2; });
        return result + dp[0];
    }
};

int main() {
    vector<int> input = {8, 9, 7, 8, 9};
    Solution t;
    cout << t.subarraysDivByK(input, 8) << endl;
}