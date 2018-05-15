#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    stack<int> s;
    vector<int> maxLeft(height.size(),0);
    vector<int> maxRight(height.size(),0);
    for(int i = 1; i < height.size(); ++i){
      maxLeft[i] = max(maxLeft[i-1],height[i-1]);
      maxRight[height.size() - 1 - i] =
	max(maxRight[height.size() - i], height[height.size() - i]);
    }

    for(int i : height){
      cout<<i<<' ';
    }
    cout<<endl;
    for(int i : maxLeft){
      cout<<i<<' ';
    }
    cout<<endl;
    for(int j : maxRight){
      cout<<j<<' ';
    }
    cout<<endl;
    return 0;
  }
};

int main(){
  vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution test;
  cout<<test.trap(input)<<endl;
}

