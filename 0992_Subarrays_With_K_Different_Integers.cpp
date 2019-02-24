#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int subarraysWithKDistinct(vector<int> &A, int K) {
        int count = 0;
        return atMost(A, K) - atMost(A, K - 1);
    }

    int atMost(vector<int> &A, int K) {
        int i = 0, res = 0;
        unordered_map<int, int> _hash;
        for (int j = 0; j < A.size(); ++j) {
            while (i < A.size()) {
                if (_hash.size() == K && _hash.find(A[i]) == _hash.end()) {
                    i = (j > i) ? j : i;
                    break;
                } else {
                    _hash[A[i++]]++;
                }
            }
            res += i - j;
            // Be careful with using [] operator
            auto it = _hash.find(A[j]);
            if (it != _hash.end() && --(it->second) == 0)
                _hash.erase(it);
        }
        return res;
    }
};

int main() {
    vector<int> input = {1, 2};
    Solution t;
    cout << t.subarraysWithKDistinct(input, 1) << endl;
    ;
    input = {1, 2, 1, 3, 4};
    cout << t.subarraysWithKDistinct(input, 3) << endl;
    ;
}