#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution{
public:
  int subarraySum(vector<int>& nums, int k){
    deque<int> subarray;
    int dequesum=0;
    int total=0;
    for(int i =0;i < nums.size();i++){
      subarray.push_back(nums[i]);
      dequesum=dequesum+nums[i];
      cout<<i<<" "<<dequesum<<endl;x
      while(k<=dequesum&&subarray.size()>0){
	if(k==dequesum){
	  total++;
	  dequesum=dequesum-subarray.front();
	  subarray.pop_front();
	}
	else{
	  dequesum=dequesum-subarray.front();
	  subarray.pop_front();
	}
      }
    }
    while(subarray.size()>0){
	if(k==dequesum){
	  total++;
	  dequesum=dequesum-subarray.front();
	  subarray.pop_front();
	}
	else{
	  dequesum=dequesum-subarray.front();
	  subarray.pop_front();
	}
      }
    return total;
  }
};

int main(){
  cout<<"Hello World"<<endl;
  int numarray[]={28,54,7,-70,22,65,-6};
  vector<int> input(numarray,numarray+sizeof(numarray)/sizeof(numarray[0]));
  Solution test;
  cout<<test.subarraySum(input,100)<<endl;
}
