#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool dec(const pair<int,int> &rhs,const pair<int,int> &lhs){
  return rhs.first>lhs.first;
}

class Solution{
public:
  vector<string> findRelativeRanks(vector<int>& nums){
    if(nums.size()==0){return {};}
    vector<string> ans(nums.size(),"");
    vector<pair<int,int> > order;
    for(int i=0;i<nums.size();i++){
      order.push_back(make_pair(nums[i],i));
    }
    //sort the array alone with index
    sort(order.begin(),order.end(),
	 [](pair<int,int> rhs,pair<int,int> lhs){return rhs.first>lhs.first;});
    for(size_t i=0;i<order.size();i++){
      if(i==0){
	ans[order[i].second]="Gold Medal";
      }else if(i==1){
	ans[order[i].second]="Solver Medal";
      }else if(i==2){
	ans[order[i].second]="Bronze Medal";
      }else{
	ans[order[i].second]=to_string(i+1);
      }
    }
    return ans;
  }
};
