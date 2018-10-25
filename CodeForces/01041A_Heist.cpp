#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heist{
public:
  int cal(vector<int>& key){
    sort(key.begin(),key.end());
    int checkStolen = key.front();
    int count = 0;
    auto unary = [&checkStolen,&count](int m){
		   while(checkStolen++ != m){ ++count; }
		 };
    for_each(key.begin(),key.end(),unary);
    return count;
  }
};


int main(){
  int n;
  cin>>n;
  Heist h;
  vector<int> input(n);
  for(auto& t : input) cin>>t;
  cout<<h.cal(input)<<endl;
}
