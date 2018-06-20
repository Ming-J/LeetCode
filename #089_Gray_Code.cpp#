#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
n = 1
 0 , 1
 0 , 1, 1, 0
n = 2
 00, 01, 11, 10
 00, 01, 11, 10, 10, 11, 01, 00
n = 3
 000, 001, 011, 010, 110, 111, 101, 100
*/
class Solution {
public:
  vector<int> grayCode(int n) {
    if(n == 0) return {0};
    vector<int> res;
    int mask;
    for(int i = 0; i < n; ++i){
      if(i+1 == 1){
	res = {0,1};
	mask = 1;
      }else{
	mask<<=1;
	int curSize = res.size();
	res.insert(res.end(),res.rbegin(),res.rend());
	transform(res.begin()+curSize, res.end(), res.begin()+curSize,
	    [mask](int x){return x^mask;});
      }
    }
    return res;
  }
};

int main(){
  Solution test;
  test.grayCode(2);
}
