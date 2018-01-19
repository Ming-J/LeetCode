#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int c1;
  int row, col;
  for(int i = 0 ; i < 5; i++){
    for( int j = 0 ; j < 5; j++){
      cin >> c1;
      if( c1 == 1){
	row = i;
	col = j;
      }
    }
  }

  cout << abs( 2 - row) + abs ( 2 - col) <<endl;
}
