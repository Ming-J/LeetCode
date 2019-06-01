#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int topDown(vector<int> &A, int lo, int hi, vector<vector<int>> &caches) {
    if (lo + 2 > hi)
      return 0;
    if (caches[lo][hi] > 0)
      return caches[lo][hi];
    int min_value = numeric_limits<int>::max();
    for (int mid = lo + 1; mid != hi; ++mid) {
      min_value = min(min_value, topDown(A, lo, mid, caches) +
		      topDown(A, mid, hi, caches) + (A[lo] *
						     A[hi] * A[mid]));
    }
    caches[lo][hi] = min_value;
    return min_value;
  }

  int minScoreTriangulation(vector<int> &A) {
    vector<vector<int>> caches(A.size(), vector<int>(A.size(), 0));
    return topDown(A,0,A.size()-1,caches);
  }
};
int main() {
  vector<int> input = {35, 73, 90, 27, 71, 80, 21, 33, 33, 13,
                       48, 12, 68, 70, 80, 36, 66, 3,  70, 58};
  Solution t;
  cout << t.minScoreTriangulation(input) << endl;
}
