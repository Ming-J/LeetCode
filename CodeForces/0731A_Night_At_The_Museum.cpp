#include <iostream>
using namespace std;

int calMoves(char a, char b){
  int dif = (a > b)? a-b : b-a;
  return min(dif,26-dif);
}

int main(){
  string str;
  cin>>str;
  int moves = 0;
  char prev = 'a';
  for(char chr:str){ 
    moves += calMoves(prev,chr);
    prev = chr;
  }
  cout<<moves<<endl;
}
