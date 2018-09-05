#include <iostream>
#include <vector>
using namespace std;

//Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals,
			  Interval newInterval) {
    if(intervals.size() == 0) return {newInterval};
    vector<Interval> inserted;
    int i = 0;
    bool added = false;
    while(i < intervals.size()){
      if(!added && newInterval.start < intervals[i].start){
	inserted.push_back(newInterval);
	added = true;
      }else{
	inserted.push_back(intervals[i]);
	++i;
      }
    }
    vector<Interval> res;
    if(!added) inserted.push_back(newInterval);
    int lo = inserted[0].start;
    int hi = inserted[0].end;
    for(int i = 1; i < inserted.size(); ++i){
      if(hi<inserted[i].start){
	res.push_back(Interval(lo,hi));
	lo = inserted[i].start;
	hi = inserted[i].end;
      }else{
	hi = (hi>inserted[i].end)?hi:inserted[i].end;
      }
    }
    res.push_back(Interval(lo.hi));
    return res;
  }
};
