#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//After looking through the discussion, there is no need to use a
//stack. It will reduce the solution from linear space to constant
//space
class Solution{
public:
  bool canJump(vector<int>& nums){
    if(nums.size()==0){return true;}
    stack<int> deck;
    deck.push(0);
    int maxIndex=0;
    while(!deck.empty()){
      int currentIndex=deck.top();
      deck.pop();
      int maxStep=currentIndex+nums[currentIndex];
      if(maxStep>=nums.size()-1){
	return true;
      }
      //checking to see if we can reach further
      if(maxStep>maxIndex){
	maxIndex=maxStep;
	for(size_t i=currentIndex+1;i<=maxIndex;i++){
	  deck.push(i);
	}
      }
    }
    return false;
  }
};
