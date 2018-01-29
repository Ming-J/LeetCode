#include <iostream>
#include <cmath>
using namespace std;

bool checkvalid(int length, int sum){
  if( (sum < 0) || sum > 9*length){
    return false;
  }
  return true;
}
int main(){
  int target = 15;
  int length = 2;
  cin>>length>>target;
  if((target == 0&&length>1) || (target > 9 * length)){
      cout<<-1<<' '<<-1<<endl;
      return 0;
  }
  int largeSum = target;
  string largest = "";
  for( int i =0 ; i < length ; i++){
    for( int j = 9 ; j >= 0 ; j--){
      if( checkvalid(length-i-1,largeSum-j)){
	largeSum -= j;
	largest += to_string(j);
	//cout<< largest<<' '<<length<<' '<<largeSum<<endl;
	j = -1;
      }
    }
  }
  int smallSum = target;
  string smallest = "";
  for( int i =0 ; i < length ; i++){
    for( int j = 0 ; j < 10 ; j++){
      if( i != 0 || j != 0){
	if( checkvalid(length-i-1,smallSum-j)){
	  smallSum -= j;
	  smallest += to_string(j);
	  //cout<< smallest<<' '<<length<<' '<<smallSum<<endl;
	  break;
	}
      }
      //cout<<i<<j<<endl;
    }
    //cout<<i<<endl;
  }
  if( largest=="0"){
    smallest = largest;
  }
  cout<<smallest<<' '<<largest<<endl;
}
