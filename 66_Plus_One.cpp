#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> plusOne(vector<int>& digits){
    if(digits.size()==0){
      return digits;
    }
    int carry=1;
    for(int i=digits.size()-1;i>=0;i--){
      if(carry==1){
	if(digits[i]+1>=10){
	  digits[i]=(digits[i]+1)%10;
	  carry=1;
	}else{
	  digits[i]=digits[i]++;
	  carry=0;
	}
      }
    }
    if(carry==1){
      vector<int> result;
      result.push_back(1);
      result.insert(result.end(),digits.begin(),digits.end());
      return result;
    }else{
      return digits;
    }
  }
};

