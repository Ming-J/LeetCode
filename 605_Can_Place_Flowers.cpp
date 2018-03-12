#include <iostream>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(flowerbed.size() < n) return false;
    int cnt = 0;
    if(flowerbed[0] == 0 && flowerbed[1] == 0){
      ++cnt;
      flowerbed[0] = 1;
    }
    for(size_t i = 1; i < flowerbed.size()-1; ++i){
      if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
	cnt++;
	flowerbed[i];
      }
    }
    if(flowerbed[flowerbed.size()-2] == 0 && flowerbed.back() == 0){
      cnt++;
    }
    return n<=cnt;
  }
};
