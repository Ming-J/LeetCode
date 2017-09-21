#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  void permutehelper(set< vector<int> >& result, vector<int> nums, vector<int> permu){
    if(nums.size()==0){
      result.insert(permu);
    }else{
      for(vector<int>::iterator i=nums.begin();i!=nums.end();i++){
	int temp=*i;
	nums.erase(i);
	permu.push_back(temp);
	permutehelper(result,nums,permu);
	permu.pop_back();
	nums.insert(i,temp);
      }
    }
  }
  
  vector<vector<int> > permuteUnique(vector<int>& nums) {
    set< vector<int> > result;
    vector<int> perm;
    permutehelper(result,nums,perm);
    vector <vector<int> > ans(result.begin(),result.end());
    return ans;
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
