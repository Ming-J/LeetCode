#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  n TV for sales
  Each TV has a price, could be negative
  Only able to carry m TV
  Maximum Sum of money that he can earn
*/

int main(){
  //inputs, n ,m, A
  int tvs, carry;
  cin>>tvs>>carry;
  vector<int> prices(tvs);
  for(auto& p:prices) cin>>p;
  //sort the array in order
  sort(prices.begin(),prices.end());
  //get all the negative value in the array based on how many TV to carry
  int money = 0;
  auto func = [&](int i){
    if(i<0 && carry>0){
      money += abs(i);
      --carry;
    }
  };
  for_each(prices.begin(),prices.end(),func);
  cout<<money<<endl;
}
