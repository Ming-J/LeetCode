#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Game{
public:
  Game(vector<int> input):nums(input){}

  int cal(){
    sort(nums.begin(),nums.end());
    size_t mid = (nums.size() - 1)/2;
    return nums[mid];
  }
private:
  vector<int> nums;
};


int main(){
  int n;
  cin>>n;
  vector<int> input(n);
  for(auto& n : input) cin>>n;
  Game t(input);
  cout<<t.cal()<<endl;
}
