#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  Sort the array based on the intervals start point and use greedy
  approach.

  After the array is sorted, iterate through the array and use a local
  variable to keep track of the smallest end point of current
  overlapping intervals. The reason is that we want to delete all
  overlapping intervals except the one that has the smallest ebd
  point, so that the next interval wont overlap wiht it.

  Time Complexity: sorting o(nlogn) , For loop o(n)
*/
//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    if(intervals.size() == 0) return 0;
    sort(intervals.begin(),intervals.end(),
	 [](Interval& lhs, Interval& rhs){
	   if(lhs.start == rhs.start){
	     return (lhs.end - lhs.start) < (rhs.end - rhs.start);
	   }else{
	     return lhs.start < rhs.start;
	   }
	 });
    int count = 0;
    int lastEnd = intervals[0].end;
    for(size_t i = 1; i < intervals.size(); ++i){
      if(lastEnd > intervals[i].start){
	lastEnd = min(intervals[i].end,lastEnd);
	++count;
      }else{
	lastEnd = intervals[i].end;
      }
    }
    return count;
  }
  void print(vector<Interval>& intervals){
    for(auto p: intervals){
      cout<<p.start<<' '<<p.end<<endl;
    }
  }
};


int main(){
  vector< pair<int,int> > p ={
    {1,2},{2,3},{1,3},{1,4}
  };
  vector<Interval> inter;
  for(auto i : p){
    inter.push_back(Interval(i.first,i.second));
  }
  Solution test;
  cout<<test.eraseOverlapIntervals(inter)<<endl;
}
