#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (k <= 0 || sum % k != 0)
      return false;
    sort(nums.begin(), nums.end(), greater<int>());
    vector<bool> visited(k, false);
    return helperDFS(nums, visited, sum / k, k, 0, 0, 0);
  }

  bool helperDFS(vector<int> &nums, vector<bool> &visited, int target, int k,
                 int cur_sum, int cur_count, int start_ind) {
    if (k == 1)
      return true;
    if (cur_sum == target && cur_count > 0)
      return helperDFS(nums, visited, target, k - 1, 0, 0, 0);
    for (size_t i = start_ind; i < nums.size(); ++i) {
      if (!visited[i]) {
        visited[i] = true;
        if (helperDFS(nums, visited, target, k, cur_sum + nums[i],
                      cur_count + 1, i + 1))
          return true;
        visited[i] = false;
      }
    }
    return false;
  }
};

int main() {
  vector<int> input = {2, 2, 2, 1,1};
  Solution test;
  if (test.canPartitionKSubsets(input, 4)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
