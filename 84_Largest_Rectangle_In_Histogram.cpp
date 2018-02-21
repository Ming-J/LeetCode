#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> deck;
    int area = 0;
    for( int he : heights){
      if(deck.empty()){
	deck.push(he);
      }else{
	if(deck.top() >  he){
	  area = max(area, calculatingArea(deck, he));
	}
	deck.push(he);
      }
    }
    area = max(area, calculatingArea(deck, 0));
    return area;
  }
  int calculatingArea(stack<int> &de, int newVal){
    int pop = 0;
    int maxArea = 0;
    while(!de.empty() && de.top() > newVal){
      pop++;
      int area = de.top() * pop;
      maxArea = max(maxArea, area);
      de.pop();
    }
    if(de.empty()){
      while(pop>0){
	de.push(newVal);
	pop--;
      }
    }else{
      while(pop>0){
	de.push(de.top());
	pop--;
      }
    }
    return maxArea;
  }
};

int main(){
  Solution test;
  vector<int> heights = {2,1,5,6,2,3};
  cout<<test.largestRectangleArea(heights);
}
