#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  Using two pointer approach. Starting from left most and right most
  to see how much water they can hold. Then we can see if we can
  improve our answer. For each of the short side, we try to see if the
  next boarder can create better solution.
*/

class Solution {
public:
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int volume = 0;
    while(i < j){
      int h = min(height[i],height[j]);
      int w = j - i;
      volume = max(volume, h*w);
      if(height[i] < height[j]){
	++i;
      }else{
	--j;
      }
    }
    return volume;
  }
};

int main(){
  Solution test;
  vector<int> height = {1,8,6,2,5,4,8,3,7};
  
}
