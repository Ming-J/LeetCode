#include <iostream>
using namespace std;

/*
  -1  > 0
  
   1 2 3 4 5
   2 3 4 5 1
   4 5 1 2 3
   
*/
//Array with no Value
{}
//One Element
{0}
//Array Not Sorted
{1,2,3,4}

//Min in the back
{2,3,4,5,0}

//min in the second half
{2,3,4,0,1}

{5,1,2,3,4}

class Solution {
public:
   int findMin(vector<int>& nums) {
     //if array is just one element then return that element
     if(nums.size() == 1) return nums[0];
     // initial the two pointers
     int lo = 0, hi = nums.size() - 1;

     //Binary Search
     while(lo < hi){
       // if out hi is greater than lo, then array is sorted
       if(nums[lo] < nums[hi])
	 return nums[lo];
       // Finding the mid point
       int mid = lo + (hi-lo)/2;

       // if you mid is greater than lo, we knoe the reflect
       //point is in the second half
       if(nums[mid] >= num[lo]){
	 lo = mid + 1;
       }else{
	 hi = mid;
       }
     }
     return nums[lo];
   }
};
