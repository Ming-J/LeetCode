#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
  int start;
  int end;
  Interval(): start(0), end(0) {}
  Interval(int s, int e): start(s), end(e) {}
};

class Solution{
public:
  vector<Interval> merge(vector<Interval>& intervals){
    if(intervals.size() < 1) return intervals;
    auto comp = [](Interval& lhs, Interval& rhs){
      if(lhs.start == rhs.start) return lhs.end < rhs.end;
      return lhs.start < rhs.start;
    };
    sort(intervals.begin(),intervals.end(),comp);
    vector<Interval> ans;
    int lo = intervals[0].start;
    int hi = intervals[0].end;
    for(size_t i = 1; i < intervals.size(); ++i){
      if(intervals[i].start > hi){
	ans.push_back(Interval(lo,hi));
	lo = intervals[i].start;
      }
      hi = max(hi,intervals[i].end);
    }
    ans.push_back(Interval(lo,hi));
    return ans;
  }
};
