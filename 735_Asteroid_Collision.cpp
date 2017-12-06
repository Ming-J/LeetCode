#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
/*use stack to store the asteroids. If new asteroids came alone
  compare the new steroid with the top of stack. If they collied then
  remove it from stack. if the asteroid don't collied we will push the
  asteroid into the stack
  O(N)
  S(N)
*/
class Solution{
public:
  vector<int> asteroidCollision(vector<int>& asteroids){
    vector<int> ans;
    stack<int> collision;
    for(int i=0;i<asteroids.size();i++){
      if(ans.empty()||ans.back()<0||(ans.back()>0&&asteroids[i]>0)){
	ans.push_back(asteroids[i]);
      }else{
	bool asteroidExist = true;
	while(!ans.empty()&&asteroids[i]<0&&ans.back()>0){
	  //same size of asteroid, both asteroid will be deleted
	  if(abs(asteroids[i])==abs(ans.back())){
	    ans.pop_back();
	    asteroidExist = false;
	    break;
	  }else if(abs(asteroids[i])>abs(ans.back())){ //new asteroid are bigger, looking for the next asteroid to compare
	    ans.pop_back();
	  }else{
	    //stack asteroid are bigger, new asteroid will be delete, no need to add into stack
	    asteroidExist=false;
	    break;
	  }
	}
	if(asteroidExist){
	  ans.push_back(asteroids[i]);
	}
      }
    }
    return ans;
  }
};
