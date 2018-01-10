#include <iostream>
using namespace std;

class Solution{
public:
  int maxProfit(vector<int>& prices){
    if(prices.size()==0){
      return 0;
    }
    int result=0;
    int buyPrice=prices[0];
    for(int i=1;i<prices.size();i++){
      if(prices[i]<price[i-1]){
	result+=prices[i-1]-buyPrice;
	buyPrice=prices[i];
      }
    }
    return result+(prices[prices.size()-1]-buyPrice);
  }
};
