#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxProfit(vector<int>& price){
    vector<pair<int,int> > priceOrder;
    int max_profit=0;
    int min_price=INT_MAX;
    for(int i=0;i<price.size();i++){
      min_price=min(min_price,price[i]);
      max_profit=max(max_profit,price[i]-min_price);
    }
    return max_profit;
  }
};
