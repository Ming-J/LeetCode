#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Sequence{
public:
  Sequence(size_t n, unsigned long long int i){
    unsigned long long int lo = 1;
    unsigned long long int hi = pow(2,n) - 1;
    while(lo <= hi){
      unsigned long long int mid = lo + (hi - lo)/2;
      if(mid == i){
	result = n;
	break;
      }
      --n;
      if(i>mid) lo = mid + 1;
      else hi = mid - 1;
    } 
  }

  int operator[](const size_t i){
    return result*i;
  }

private:
  vector<int> seq;
  int result;
};


int main(){
  size_t n = 38;
  unsigned long long int t = 137438953472;
  cin>>n>>t;
  Sequence te(n,t);
  cout<<te[1]<<endl;
}
