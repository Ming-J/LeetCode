#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> price(n,0);
  for(auto& p: price){
    cin>>p;
  }
  sort(price.begin(),price.end());
  int days;
  cin>>days;
  for(int i = 0; i < days; ++i){
    int budget;
    cin>>budget;
    //Upper_bound return position of next higher number than num
    //Subtracting the pointer to 1st position returns the actual index
    cout<<upper_bound(price.begin(),price.end(),budget) - price.begin()<<endl;
  }
}
