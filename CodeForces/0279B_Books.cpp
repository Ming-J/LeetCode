#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
  int books, times;
  cin>>books>>times;
  vector<int> table;
  for(int i = 0; i < books; ++i){
    int t;
    cin>>t;
    table.push_back(t);
  }
  vector<int> sum(books+1,0);
  partial_sum(table.begin(),table.end(),sum.begin()+1);
  int lo = 1;
  int hi = 1;
  int maxInterval = 0;
  while(lo<sum.size()&&hi<sum.size()){
    if(sum[hi]-sum[lo - 1] > times){
      ++lo;
    }else{
      maxInterval = max(maxInterval, (hi-lo)+1);
      ++hi;
    }
  }
  cout<<maxInterval<<endl;
}
