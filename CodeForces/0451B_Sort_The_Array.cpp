#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  //#ifdef _DEBUG
  //ifstream cin("input.txt");
  //#endif
  int n;
  cin>>n;
  vector<int> nums(n);
  for(auto& a:nums) cin>>a;
  int ascd = -1;
  int desc = -1;
  for(size_t i = 0; i < nums.size() - 1; ++i){
    if(nums[i] > nums[i+1]){
      desc = i;
      break;
    }
  }
  for(size_t i = nums.size() - 1; i > 0; --i){
    if(nums[i] < nums[i-1]){
      ascd = i;
      break;
    }
  }
  if(ascd != -1 && desc != -1) reverse(nums.begin()+desc,nums.begin()+ascd+1);
  //cout<<ascd<<" "<<desc<<endl;
  if(is_sorted(nums.begin(),nums.end())){
    cout<<"yes"<<endl;
    if(ascd != -1 && desc != -1) cout<<desc+1<<' '<<ascd+1<<endl;
    else cout<<1<<' '<<1<<endl;
  }else{
    cout<<"no"<<endl;
  }
}
