#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
      //Distributing one Candy to each Student
      vector<int> candys(ratings.size(),1);
      //checking the left rating,
      //if the current rating are higher than increment
      for(size_t i = 1; i < ratings.size(); ++i){
	if(ratings[i-1] < ratings[i]){
	  candys[i] = candys[i-1] + 1;
	}
      }
      //checking the right rating; if current higher than right
      //then check if the previous candy count against incrementing from right 
      for(size_t i = ratings.size() - 2; i < ratings.size(); --i){
	if(ratings[i] > ratings[i+1]){
	  candys[i] = max(candys[i],candys[i+1] +1);
	}
      }
      return accumulate(candys.begin(),candys.end(),0);
    }
};
