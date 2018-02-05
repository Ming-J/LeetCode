#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int sum = 0;
    int currBuy = 0;
    int currSell = 0;
    for( int i = 0; i < prices.size(); i++){
      if( prices[i-1] - prices[i] > 2 ){
	currSell = prices[i-1];
	sum += (currSell - currBuy) - 2;
	currBuy = price[i];
      }
    }
    return sum;
  }
};
