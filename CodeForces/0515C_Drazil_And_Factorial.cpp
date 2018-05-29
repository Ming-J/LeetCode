#include <iostream>
#include <vector>
using namespace std;

void addCount(vector<int>& cnt, int num, int increment){
  cnt[num] += increment;
}

int main(){
  vector<int> count(10,0);
  int n;
  cin>>n;
  string str;
  cin>>str;
  for(char c:str){
    int digit = c - '0';
    switch(digit){
    case 0:
    case 1:
      break;
    case 4:
      // 4! = 3!*2!*2!
      addCount(count,2,2);
      addCount(count,3,1);
      break;
    case 6:
      // 6! = 5!*3!
      addCount(count,5,1);
      addCount(count,3,1);
      break;
    case 8:
      // 8! = 7! * 2! * 2 ! * 2!
      addCount(count,7,1);
      addCount(count,2,3);
      break;
    case 9:
      //9! = 7! * 3! * 3! * 2!
      addCount(count,7,1);
      addCount(count,3,2);
      addCount(count,2,1);
      break;
    default:
      addCount(count,digit,1);
    }
  }
  for(size_t i = count.size() - 1; i < count.size(); --i){
    for(size_t j = count[i]; j != 0; --j){
      cout<<i;
    }
  } 
}
