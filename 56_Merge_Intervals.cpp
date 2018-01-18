#include <iostream>
#include <vector>
#include <algorithm>
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
  vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(),intervals.end(),
	 [](Interval lhs,Interval rhs){
	   if(lhs.start == rhs.start){
	     return lhs.end < rhs.end;
	   }else{
	     return lhs.start < rhs.start;
	   }
	 });
    vector<Interval> res;
    for( auto i : intervals){
      if(res.empty()){
	res.push_back(i);
      }else{
	if(res.back().end >= i.start){
	  res.back().end =
	    res.back().end<=i.end ? i.end : res.back().end;
	}else{
	  res.push_back(i);
	}
      }
      cout<<i.start<<"  "<<i.end<<endl;
    }
    return res;
  }
};
