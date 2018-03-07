#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool checkqusi(int n){
  while(n > 0){
    int remainder = n % 10;
    if( remainder % 10 != 1 && remainder % 10 != 0){
      return false;
    }
    n /= 10;
  }
  return true;
}

void qusibinary(int &val,int s){
  vector<int> binaryTable;
  for(int i = 0; i <= s; ++i){
    if(checkqusi(i)) binaryTable.push_back(i);
  }
  vector<int> sum(val+1,INT_MAX);
  vector<int> prev(val+1,0);
  sum[0] = 0;
  for(size_t i = 1; i < sum.size(); ++i){
    int minVal = INT_MAX;
    for(size_t j = 0;
	j < binaryTable.size() &&
	  (static_cast<int>(i) - binaryTable[j]) >= 0; ++j){
      if( minVal > sum[static_cast<int>(i) - binaryTable[j]]){
	minVal = sum[static_cast<int>(i) - binaryTable[j]];
	prev[i] = binaryTable[j];
      }
    }
    sum[i] = minVal+1;
  }
  int cnt = 0;
  cout<<sum[val]<<endl;
  while(val > 0){
    cout<<prev[val]<<' ';
    val -= prev[val];
  }
}

int main(){
  int val;
  cin>>val;
  qusibinary(val,val);
}
