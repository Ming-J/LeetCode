#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Array{
public:
  Array(vector<int> A){
    for_each(A.begin(),A.end(),[&](int i){++count[i];});
  }
  int calculate(){
    if(count.size() < 2) return 0;
    int open_place = 0;
    int ans = 0;
    for(auto ele : count){
      int cnt = ele.second;
      int delta = min(cnt, open_place);
      ans += delta;
      open_place += cnt - delta;      
    }
    return ans;
  }
private:
  map<int,int> count;
};


int main(){
  int L;
  cin>>L;
  vector<int> input(L);
  for(auto& n : input) cin>>n;
  Array temo(input);
  cout<<temo.calculate();
}
