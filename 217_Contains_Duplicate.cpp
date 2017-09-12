/*Given an array of integers, find if the array contains any
  duplicates. Your function should return true if any value appears at
  least twice in the array, and it should return false if every
  element is distinct.

using hash table. Check for duplicate.
Time Complexity: O(N)
Space Complecity: O(N)
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> hash;
      unordered_set<int>::iterator it;
      for(int i=0;i<nums.size();i++){
	it=hash.find(nums[i]);
	if(it==hash.end()){
	  hash.insert(nums[i]);
	}else{
	  return true;
	}
      }
      return false;
    }
};
