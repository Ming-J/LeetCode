/*
Find all possible combinations of k numbers that add up to a number n,
given that only numbers from 1 to 9 can be used and each combination
should be a unique set of numbers.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]


Using backtracking to slove this problem. Too find all the combination
of a set and see if there total equal to the value we want. Using a
start int to avoid duplicate number added into the set.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int>  > combinationSum3(int k, int n){
    vector< vector<int> > result;
    vector<int> sett;
    combinationHelper(result, sett,1, 0, k, n);
    return result;
  }

  void combinationHelper(vector< vector<int> > &result,vector<int> combination,int start,int total, int k, int n){
    if(combination.size()==k){
      if(total==n){
	  result.push_back(combination);
	}
    }else{
      for(int i=start;i<10;i++){
	  combination.push_back(i);
	  print(combination);
	  combinationHelper(result,combination,i+1,total+i,k,n);
	  combination.pop_back();
	}
      }
  }
  
  void print(vector<int> combination){
    for(int i=0;i<combination.size();i++){
      cout<<"  ";
    }
    for(int i=0;i<combination.size();i++){
      cout<<combination[i];
    }
    cout<<endl;
  }
};
