#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> asteroidCollision(vector<int>& asteroids){
    vector<int> ans;
    stack<int> collision;
    for(int i=0;i<asteroids.size();i++){
      if(ans.empty()){
	ans.push_back(asteroids[i]);
      }else{
	while(!ans.empty()&&asteroids[i]*ans.back()<0){
	  if(abs(asteroids[i])==abs(ans.back())){
	    ans.pop_back();
	    break;
	  }else if(abs(asteroids[i])>abs(ans.back())){
	    ans.pop_back();	    
	  }else{
	    break;
	  }
	}
	if(ans.empty()){
	  ans.push_back(asteroids[i]);
	}
      }
    }
    return ans;
  }
};
