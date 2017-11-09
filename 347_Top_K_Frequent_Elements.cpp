/*
Given a non-empty array of integers, return the k most frequent
elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: You may assume k is always valid, 1 ≤ k ≤ number of unique
elements.  Your algorithm's time complexity must be better than O(n
log n), where n is the array's size.


Can also use Bucket sort, create a list for each of the frequency
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      //inserting the frequency into a hash table
      unordered_map<int,int> hash;
      int bucket=0;
      for(int i=0;i<nums.size();i++){
	  hash[nums[i]]++;
	  bucket=max(bucket,hash[nums[i]]);
	  //increament when the value is already in
      }
      vector< vector<int> > bucketlist(bucket,vector<int>);
      vector<pair<int,int>> freq;
      for(auto i=hash.begin();i!=hash.end();i++){
	bucketlist[i->second-1].push_back(i->first);
      }
      vector<int> res;
      for(int i=bucketlist.size();i>=0;i--){
	for(int j=bucketlist[i].size();j>=0;j--){
	  if(res.size()<k){
	    res.push_back(bucketlist[i][j]);
	  }
	}
      }
      return res;
      //insert into an vector for sorting according to frequency
      vector<pair<int,int>> freq;
      for(auto i=hash.begin();i!=hash.end();i++){
	freq.push_back(make_pair(i->first,i->second));
      }
      sort(freq.begin(),freq.end(),
      [](pair<int,int> lhs,pair<int,int> rhs){return lhs.second>rhs.second;});
      //return the most top k frequent element
      vector<int> res;
      for(int i=0;i<k;i++){
	res.push_back(freq[i].first);
      }
      return res;
    }
};
