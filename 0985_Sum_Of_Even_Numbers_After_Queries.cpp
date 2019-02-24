#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> sumEvenAfterQueries(vector<int> &A,
                                    vector<vector<int>> &queries) {
        vector<int> res;
        auto func = [](int acc, int cur) {
            if (cur % 2 == 0)
                acc += cur;
            return acc;
        };
        int sumvalue = accumulate(A.begin(), A.end(), 0, func);
        for (auto q : queries) {
            int ind = q[1], val = q[0];
            if (abs(A[ind]) % 2 == 0 && abs(val) % 2 == 0) {
                sumvalue += val;
            }
            if (abs(A[ind]) % 2 == 1 && abs(val) % 2 == 1) {
                sumvalue += (A[ind] + val);
            }
            if (abs(A[ind]) % 2 == 0 && abs(val) % 2 == 1) {
                sumvalue -= A[ind];
            }
            A[ind] += val;
            res.push_back(sumvalue);
        }
        return res;
    }
};

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<vector<int>> Q;
    Solution t;
    t.sumEvenAfterQueries(A, Q);
    return 0;
}