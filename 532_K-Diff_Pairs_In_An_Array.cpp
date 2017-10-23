#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
/*Given an array of integers and an integer k, you need to find the
  number of unique k-diff pairs in the array. Here a k-diff pair is
  defined as an integer pair (i, j), where i and j are both numbers in
  the array and their absolute difference is k.
Time: O(n)
Space:O(n)
 */
class Solution{
public:
  int findPairs(vector<int>& nums, int k){
    if(k<0){   //absolute difference can not be negative
      return 0;
    }
    unordered_map<int,int> hash;
    unordered_map<int,int>::iterator it;
    //inserting all element into hashtable
    //increase the count for duplicate value
    for(size_t i=0;i<nums.size();i++){
      it=hash.find(nums[i]);
      if(it==hash.end()){
	hash[nums[i]];
      }else{
	hash[nums[i]]++;
      }
    }
    int count=0;
    //Going through all element in hash
    for(it=hash.begin();it!=hash.end();hash.erase(it++)){
      // k=0, mean we have to check for duplicate very in array
      // so we check the second element of the hash value
      if(k==0){
	if(it->second>0){
	  count++;
	}
      }else{
	//checking both value that could lead to absolute diff
	int up=it->first+k;
	int down=it->first-k;
	unordered_map<int,int>::iterator get=hash.find(up);
	if(get!=hash.end()){
	  count++;
	}
	get=hash.find(down);
	if(get!=hash.end()){
	  count++;
	}
      }
    }
    return count;
  }
};
