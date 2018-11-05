#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Permutation{
public:
  Permutation(vector<int> n):nums{n}{}
  unsigned long long int diff(){
    sort(nums.begin(),nums.end());
    int n = 1;
    unsigned long long int diff = 0;
    auto func = [&](int v){
		  diff += abs((n++)-v);
		};
    for_each(nums.begin(),nums.end(),func);
    return diff;
  }
private:
  vector<int> nums;
};


int main(){
  int t;
  cin>>t;
  vector<int> arr(t);
  for(auto& n : arr) cin>>n;
  Permutation temp(arr);
  cout<<temp.diff()<<endl;
}
