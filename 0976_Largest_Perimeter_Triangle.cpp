#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// sorted, try the last three, if not possible, shift the next three to left

class Solution {
  public:
    int largestPerimeter(vector<int> &A) {
        sort(A.begin(), A.end());
        int size = A.size();
        int a = size - 3, b = size - 2, c = size - 1;
        while (a >= 0) {
            if (checkTri(A[a], A[b], A[c])) {
                return A[a] + A[b] + A[c];
            }
            --a;
            --b;
            --c;
        }
        return 0;
    }

  private:
    bool checkTri(long a, long b, long c) {
        return a + b > c && b + c > a && a + c > b;
    }
};

int main() {
    Solution t;
    vector<int> input = {3, 6, 2, 3};
    assert(t.largestPerimeter(input) == 8);
    input = {3, 2, 3, 4};
    assert(t.largestPerimeter(input) == 10);
    input = {1, 2, 1};
    assert(t.largestPerimeter(input) == 0);
}
