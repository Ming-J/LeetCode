/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.

Given the question is already sorted, we can use binary search
method. Do a binary search on the row first to decide which rows. Then
do a binary search on the column. If no such item, we return false.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
      int row=-1;
      int start=0;
      int end=matrix.size()-1;
      int mid;
      while(start<=end){
	mid=start+(end-start)/2;
	if(matrix[mid][0]==target){
	  return true;
	}else if(matrix[mid][0]>target){
	  end = mid-1;
	}else{
	  start = mid+1;
	}
      }
      row=end;
      if(row<0){
	return false;
      }
      start=0;
      end=matrix[row].size()-1;
      while(start<=end){
	mid=start+(end-start)/2;
	if(martix[row][mid]==target){
	  return true;
	}else if(target<matrix[row][mid]){
	  end=mid-1;
	}else{
	  start=mid+1;
	}
      }
      return false;
      /*
	if(mid==0){if(matrix[row][mid]==target){return true;}else{return false;}};
	if(mid==matrix.size()-1){if(matrix[row][mid]==target){return true;}else{return false;}};
	iscol=matrix[row][mid-1]<target&&matrix[row][mid+1]>target;
	if(iscol){
	  if(matrix[ row][mid]==target){
	    return true;
	  }else{
	    return false;
	  }
	}
	if(target<matrix[row][mid]){
	  end=mid-1;
	}else{
	  start=mid+1;
      }
      }*/
};

int main(){
  vector<int> row;
  row.push_back(1);
  vector< vector<int> > input;
  input.push_back(row);
  Solution test;
  test.searchMatrix(input,1);
}
