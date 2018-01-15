#include <iostream>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      if(n==1){
	return n;
      }
      int lo=1;
      int hi=n;
      while(lo<=hi){
	int mid=lo+(hi-lo)/2;
	bool midB=isBadVersion(mid);
	if(midB){
	  if(isBadVersion(mid-1)){
	    return mid;
	  }else{
	    hi=mid-1;
	  }
	}else{
	  if(isBadVersion(mid+1)){
	    lo=mid+1;
	  }else{
	    return mid;
	  }
	}
      }
    }
};
