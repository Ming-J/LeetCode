#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long long int> nums(n,0);
  for(auto &m:nums){
    cin>>m;
  }
  sort(nums.begin(),nums.end());
  unsigned long long int sum = 0;
  auto func = [&nums,count = 0](unsigned long long int s,long long int a)mutable{
    if(count > 0) s += nums[count-1];
    return s += a*(++count);
  };
  cout<<accumulate(nums.begin(),nums.end(),sum,func)<<endl;;
  //cout<<sum<<endl;
}
