#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k=k%nums.size();
      vector<int> temp(nums.begin(),nums.end());
      int index=0;
      for(int i=temp.size()-k;i<temp.size();i++){
	nums[index]=temp[i];
	index++;
      }
      for(int i=0;i<temp.size()-k;i++){
	nums[index]=temp[i];
	index++;
      }
    }
};

int main(){
  cout<<"Hello World"<<endl;
}
