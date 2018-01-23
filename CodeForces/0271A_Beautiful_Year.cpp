#include <iostream>
using namespace std;

bool checkDistinct(int year){
  int numarr[10]={0};
  while(year>0){
    int mod = year % 10;
    if( numarr[mod] == 1){
      return false;
    }
    numarr[mod]++;
    year /=10;
  }
  return true;
}

int main(){
  int year;
  cin >> year;
  year++;
  while(!checkDistinct(year)){
    year++;
  }
  cout<<year<<endl;
}
