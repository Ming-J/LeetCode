#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        return findpartition(nums, nums.size());
    }

  private:
    bool isSubSet(vector<int> &nums, int n, int sum) {
        vector<bool> prev(sum + 1, false);
        prev[0] = true;
        for (size_t i = 0; i < nums.size(); ++i) {
            vector<bool> current = prev;
            for (size_t j = 0; j < prev.size(); ++j) {
                if (prev[j] && nums[i] + j < prev.size()) {
                    current[nums[i] + j] = true;
                }
            }
            prev = current;
        }
        return prev[sum];
    }
    bool findpartition(vector<int> &nums, int n) {
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (sum % 2 == 1)
            return false;
        return isSubSet(nums, n, sum / 2);
    }
};

int main() {
    vector<int> input = {5, 1, 2, 2};
    Solution test;
    if (test.canPartition(input)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}