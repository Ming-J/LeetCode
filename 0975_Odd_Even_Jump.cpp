#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
  public:
    int oddEvenJumps(vector<int> &A) {
        int res = 1;
        vector<int> high(A.size()), low(A.size());
        high.back() = low.back() = 1;
        map<int, int> mp;
        mp.insert(make_pair(A.back(), A.size() - 1));
        for (size_t i = A.size() - 2; i < A.size(); --i) {
            // lower bound first element key is not consider to go before
            // k(either same or after)

            // upper bound first element key after the K
            auto hi = mp.lower_bound(A[i]), lo = mp.upper_bound(A[i]);
            if (hi != mp.end())
                high[i] = low[hi->second];
            if (lo != mp.begin())
                low[i] = high[(--lo)->second];
            if (high[i] == 1) {
                ++res;
            }
            mp.insert_or_assign(A[i], i);
        }
        return res;
    }
};

int main() {
    vector<int> inputs = {5, 1, 3, 4, 2};
    Solution t;
    cout << t.oddEvenJumps(inputs);
}