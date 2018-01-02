#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findMinDifference(vector<string>& timePoints){
    //using lambda function to sort the time
    sort(timePoints.begin(),timePoints.end(),
	 [](string lhs,string rhs){
	   string lhsHour=lhs.substr(0,2);
	   string lhsMin=lhs.substr(3,2);
	   string rhsHour=rhs.substr(0,2);
	   string rhsMin=rhs.substr(3,2);
	   if(lhsHour==rhsHour){
	     return lhsMin<rhsMin;
	   }else{
	     return lhsHour<rhsHour;
	   }
	 });
    int mindiff=24*60;
    //calculating minimum minute different between the circular array
    for(int i=0;i<timePoints.size();i++){
      if(i==timePoints.size()-1){
	mindiff=min(mindiff,24*60-calDiff(timePoints[0],timePoints[i]));
      }else{
	mindiff=min(mindiff,calDiff(timePoints[i],timePoints[i+1]));
      }
      cout<<timePoints[i]<<endl;
    }
    return mindiff;
  }
  //calculating the minutes difference between two times
  int calDiff(string time1,string time2){
    int time1Hour=stoi(time1.substr(0,2));
    int time1Min=stoi(time1.substr(3,2));
    int time2Hour=stoi(time2.substr(0,2));
    int time2Min=stoi(time2.substr(3,2));
    int diff=time2Min-time1Min;
    if(diff<0){ time2Hour--; diff+=60; }
    diff+=(time2Hour-time1Hour)*60;
      return diff;
  }
};
