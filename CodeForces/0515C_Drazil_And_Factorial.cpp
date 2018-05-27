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
  string std;
  cin>>str;
  for(char c:str){
    switch(c-'0'){
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
    }
  }
}
