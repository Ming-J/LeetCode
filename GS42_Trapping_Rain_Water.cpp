#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      //Maximum height to the left hand side of current position
      vector<int> left(height.size(),0);
      //maximum height to the right hand side of current position
      vector<int> right(height.size(),0);
      //Getting the dp table
      for(int i = 0, j = height.size()-1; i < height.size(); ++i,--j){
	if(j == height.size()-1 && i == 0){
	  left[i] = 0;
	  right[j] = 0;
	}else{
	  left[i] = max(left[i-1],height[i-1]);
	  right[j] = max(right[j+1],height[j+1]);
	}
      }
      int water = 0;
      //find how much water can hold at the current position
      for(int i = 0; i < height.size(); ++i){
	int currentTrap = min(left[i],right[i])-height[i];
	water += (currentTrap>0)?currentTrap:0;
      }
      return water;
    }
};
