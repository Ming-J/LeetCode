#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if( timeSeries.size() == 0) return 0;
    int poisoned = duration;
    int previousPois = timeSeries[0] + duration - 1;
    for(size_t i = 1; i < timeSeries.size(); i++){
      int til = timeSeries[i] + duration - 1;
      //checking for overlapping
      if(previousPois >= timeSeries[i]){
	poisoned += duration - (previousPois-timeSeries[i]+1);
      }else{
	poisoned += duration;
      }
      previousPois = til;
    }
    return poisoned;
  }
};

int main(){
  Solution test;
  vector<int> arr = {1,2};
  int dur = 2;
  cout<<test.findPoisonedDuration(arr,dur);
}
