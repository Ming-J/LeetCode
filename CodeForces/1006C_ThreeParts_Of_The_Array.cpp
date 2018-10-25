#include <iostream>
#include <vector>
using namespace std;

class Split{
public:
  unsigned long long int findMaxA(vector<int>& array){
    unsigned long long int maxA = 0;
    size_t lo = 0, hi = array.size() -1;
    unsigned long long int loSum = array[lo], hiSum = array[hi];
    while(lo < hi){
      if(loSum == hiSum){
	maxA = max(loSum, maxA);
	loSum += array[++lo];
	hiSum += array[--hi];
      }else if(loSum > hiSum){
	hiSum += array[--hi];
      }else{
	loSum += array[++lo];
      }
    }
    return maxA;
  }

};


int main(){
  int n;
  cin>>n;
  vector<int> input(n,0);
  for(auto& temp : input) cin>>temp;
  Split t;
  cout<<t.findMaxA(input)<<endl;
}
