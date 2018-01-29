#include <iostream>
#include <cmath>
using namespace std;
/*
 *
*/
bool checkvalid(int length, int sum){
  if( (sum < 0) || sum > 9*length){
    return false;
  }
  return true;
}

int main(){
  int target, length;
  cin>>length>>target;
  // boundy check, see if it's possible. not possible if the target is
  // greater than the length*9
  if((target == 0&&length>1) || (target > 9 * length)){
      cout<<-1<<' '<<-1<<endl;
      return 0;
  }
  //finding the largest, with greedy algorithm
  int largeSum = target;
  string largest = "";
  for( int i =0 ; i < length ; i++){
    for( int j = 9 ; j >= 0 ; j--){
      if( checkvalid(length-i-1,largeSum-j)){
	largeSum -= j;
	largest += to_string(j);
	j = -1;
      }
    }
  }
  //finding the smallest, with greedy algorithm
  int smallSum = target;
  string smallest = "";
  for( int i =0 ; i < length ; i++){
    for( int j = 0 ; j < 10 ; j++){
      if( i != 0 || j != 0){
	if( checkvalid(length-i-1,smallSum-j)){
	  smallSum -= j;
	  smallest += to_string(j);
	  break;
	}
      }
    }
  }
  if( largest=="0"){
    smallest = largest;
  }
  cout<<smallest<<' '<<largest<<endl;
}
