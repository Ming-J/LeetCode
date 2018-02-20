#include <iostream>
#include <vector>
using namespace std;
// To find the increasing interval, we just have to change if the
// current value are greater, increment if it's greater else reset to
// 1
class Increase{
public:
  int maxIncrease(vector<int> arr){
    int interval = 1;
    int maxPeak = 1;
    for( size_t i = 1; i < arr.size(); i++){
      if(arr[i-1] < arr[i]){
	interval++;
      }else{
	interval = 1;
      }
      maxPeak = max(maxPeak,interval);
    }
    return maxPeak;
  }
};

int main(){
  int n;
  cin>>n;
  vector<int> input(n);
  for( int i = 0; i < n; i++){
    int temp;
    cin>>temp;
    input[i] = temp;
  }
  Increase a702;
  cout<<a702.maxIncrease(input);
}
