#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int numSquarefulPerms(vector<int> &A) {
        unordered_map<int, int> occurance;
        for (auto n : A)
            occurance[n]++;
        unordered_map<int, unordered_set<int>> candidiate;
        for (auto i : occurance) {
            for (auto j : occurance) {
                int x = i.first, y = j.first, sum = x + y, sq = sqrt(sum);
                if (sq * sq == sum)
                    candidiate[x].insert(y);
            }
        }
        int ans = 0;
        for (auto i : occurance) {
            backtrack(occurance, candidiate, ans, i.first, A.size() - 1);
        }
        return ans;
    }

  private:
    void backtrack(unordered_map<int, int> &occur,
                   unordered_map<int, unordered_set<int>> &cand, int &ans,
                   int val, int cur_array_size) {
        occur[val]--;
        if (cur_array_size == 0)
            ++ans;
        for (int n_to_square : cand[val]) {
            if (occur[n_to_square] > 0) {
                backtrack(occur, cand, ans, n_to_square, cur_array_size - 1);
            }
        }
        occur[val]++;
    }
};
int main() {
    Solution t;
    vector<int> input = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    cout << t.numSquarefulPerms(input) << endl;
}