/*
1, 0, -1, 0, -2, 2

1,0,-1,0  1,0,-1,-2  1,0,-1,2
0,-1,0,-2  0,-1,0,2


 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector< vector<int> >fourSum(vector<int>& nums, int target){
    vector< vector<int> > ans;
    int counter=0;
    for(int i=0;i<nums.size();i++){
      for(int j=0; j<nums.size();j++){
	for(int k=0; k<nums.size();k++){
	  if(i!=j&&j!=k&&k!=i){
	    counter++;
	    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
	  }
	}
      }
    }
    cout<<counter<<endl;
    return ans;
  }
};

int main(){
  int arr[6]={4,3,-1,2,-2,10};
  vector<int> input(arr,sizeof arr/arr[0]+arr);
  Solution test;
  test.fourSum(input,0);
  cout<<"Hello World"<<endl;
}
