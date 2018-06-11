#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
/*
  Price for a kilo.  A yuan for b kilo a/b yuan for a kilo
  m kilo of apple, 

n supermarkets  and need m kilo of apple

a yuan for b kilo of apple

*/
int main(){
  int superMarket, apple;
  cin>>superMarket>>apple;
  double minPrice = numeric_limits<double>::max();
  for(int i = 0; i < superMarket; ++i){
    int yuan, kilo;
    cin>>yuan>>kilo;
    double p = static_cast<double>(yuan)/static_cast<double>(kilo);
    minPrice = min(minPrice,p);
  }
  cout<<setprecision(9)<<apple*minPrice<<endl;
}
