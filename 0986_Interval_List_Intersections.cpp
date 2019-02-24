#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
  public:
    vector<Interval> intervalIntersection(vector<Interval> &A,
                                          vector<Interval> &B) {
        vector<Interval> ans;
        int a_i = 0, b_i = 0;
        while (a_i < A.size() && b_i < B.size()) {
            Interval a = A[a_i], b = B[b_i];
            if (a.end < b.start) {
                ++a_i;
            } else if (b.end < a.start) {
                ++b_i;
            } else {
                ans.push_back(
                    Interval(max(a.start, b.start), min(a.end, b.end)));
                if (a.end < b.end) {
                    ++a_i;
                } else {
                    ++b_i;
                }
            }
        }
        return ans;
    }
};