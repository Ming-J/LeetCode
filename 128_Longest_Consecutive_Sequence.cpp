/*==============================================================================
Given an unsorted array of integers, find the length of the longest
consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.  

Time complexity: O(n)
Space Complecity: O(n)
 
Insert the given array to an unorder set. The reason we used unorder
set it's because it provide O(1) insert/ find. After the thing is
inserted, we travese through the array. Find the element in the set
and check to see if it has +1 or -1 are in the set as well, and
continue to +2 or -2. Once found, we delete the value from the unorder
set.
 ===============================================================================*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
  int longestConsecutive(vector<int>& nums){
    unordered_set<int> hash;
    hash.insert(nums.begin(),nums.end());
    int counter=0;
    int result=0;
    for(int i=0;i<nums.size();i++){
      unordered_set<int>::iterator it;
      int value=nums[i];
      it=hash.find(value);
      if(it!=hash.end()){
	counter=1;
	int j=1;
	while(hash.find(value+j)!=hash.end()){
	  counter++;
	  hash.erase(value+j);
	  j++;
	}
	j=1;
	while(hash.find(value-j)!=hash.end()){
	  counter++;
	  hash.erase(value-j);
	  j++;
	}
      }
      if(counter>result){
	result=counter;
      }
    }
    return result;
  }
};

int main(){
  Solution test;
  vector<int> input;
  input.push_back(100);
  input.push_back(4);
  input.push_back(200);
  input.push_back(1);
  input.push_back(3);
  input.push_back(2);
  cout<<test.longestConsecutive(input)<<endl;
}
