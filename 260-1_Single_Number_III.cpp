#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
  vector<int> singleNumber(vector<int>& nums){
    int axorb=0;
    for(int i=0;i<nums.size();i++){
      axorb=axorb^nums[i];
    }
    int mask= axorb ^ ( axorb& (axorb-1));
    int p=0;
    int q=0;
    for(int i=0;i<nums.size();i++){
      if( (nums[i] & mask) ==0){
	p=p^nums[i];
      }else{
	q=q^nums[i];
      }
    }
    vector<int> result;
    result.push_back(q);
    result.push_back(p);
    return result;
  }
};

int main(){
  int num[6]={1,2,1,3,2,5};
  vector<int> input(num,num+6);
  Solution result;
  result.singleNumber(input);
}
