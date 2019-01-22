#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int maxProd = nums[0];
        for (int i = 1, imax = nums[0], imin = nums[0]; i < nums.size(); ++i) {
            // multiple a negative number make a big number small, small number
            // bigger
            if (nums[i] < 0)
                swap(imin, imax);

            // max/min product for the current number is either the current
            // number itself or the max/min of previous time the current
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            // the newlyt compute max value is a candidate for our global reuslt
            maxProd = max(imax, maxProd);
        }
        return maxProd;
    }
};

int main() {
    Solution test;
    vector<int> input = {2, -5, -2, -4, 3};
    cout << test.maxProduct(input) << endl;
}