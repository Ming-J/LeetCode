#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;
/* Completed using bit manuplation 
 * 
*/
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector< vector<int> > res;
    int bitsize = pow(2,nums.size());
    bitset<100> f00;
    int value = 0;
    while( bitsize > value ){
      f00 = value;
      vector<int> set;
      for( int i = 0; i < nums.size() ;i++){
	if(f00[i] == 1){
	  set.push_back(nums[i]);
	}
      }
      res.push_back(set);
      value++; 
    } 
    return res;
  }
};

int main(){
  Solution test;
  vector<int> input = {1,2,3};
  vector< vector<int> > result = test.subsets(input);
  for( int i = 0; i < result.size(); i++){
    for( auto j : result[i] ){
      cout<<j<<' ';
    }
    cout<<endl;
  }
}
