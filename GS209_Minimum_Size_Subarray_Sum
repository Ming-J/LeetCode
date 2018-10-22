#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    size_t minLen = numeric_limits<size_t>::max();
    queue<int> window;
    int windowSum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      // Adding each individal number to the queue
      windowSum += nums[i];
      window.push(nums[i]);
      if (windowSum >= s) {
        // Removing the excessive
        while (!window.empty() && windowSum >= s) {
	  minLen = min(minLen, window.size());
	  windowSum -= window.front();
          window.pop();
        }
      }
    }
    return minLen > nums.size() ? 0 : minLen;
  }
};

int main() {
  vector<int> input = {2, 3, 1, 2, 4, 3};
  int s = 7;
  Solution test;
  cout << test.minSubArrayLen(s, input) << endl;
}
