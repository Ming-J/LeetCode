#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> bills = {1,5,10,20,100};
  long n;
  cin>>n;
  long hundred = n / 100;
  n %= 100;
  vector<int> dp(n+1);
  for(size_t i = 1; i < dp.size(); ++i){
    int minBill = INT_MAX;
    for(size_t j = 0; j < bills.size(); ++j){
      int index = i - bills[j];
      if(index >= 0){
	minBill = min(minBill, dp[index] +1);
      }
    }
    dp[i] = minBill;
  }
  cout<<hundred + dp[n]<<endl;
}
