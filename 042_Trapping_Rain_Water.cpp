#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    stack< pair<int,int> > s;
    int volume = 0;
    for(size_t i = 0; i < height.size(); ++i){
      int prevHeight = 0;
      while(!s.empty()){
	int bar = s.top().first;
	int pos = s.top().second;
	volume += (min(bar,height[i]) - prevHeight) * (i - pos - 1);
	prevHeight = bar;
	if(height[i] < bar){
	  break;
	}else{
	  s.pop();
	}
      }
      s.push(make_pair(height[i],i));
    }
    vector<int> maxLeft(height.size(),0);
    vector<int> maxRight(height.size(),0);
    for(int i = 1; i < height.size(); ++i){
      maxLeft[i] = max(maxLeft[i-1],height[i-1]);
      maxRight[height.size() - 1 - i] =
	max(maxRight[height.size() - i], height[height.size() - i]);
    }
    int sum = 0;
    for(size_t i = 0; i < height.size(); ++i){
      int minheight = min(maxLeft[i],maxRight[i]);
      if(minheight > height[i]){
	cout<<i<<' '<<minheight-height[i]<<endl;
	sum += minheight - height[i]; 
      }
    }
    return sum;
  }
};

int main(){
  vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution test;
  cout<<test.trap(input)<<endl;
}

