#include <iostream>
#include <vector>
using namespace std;

long long int maxPoint(int i, vector<int> &count){
  vector<unsigned long long int> pointArr(i+1,0);
  for( int j = 0 ; j < pointArr.size() ; j++){
    if( j == 0 ){
      pointArr[j] = 0;
    }else if( j == 1 ){
      pointArr[j] = count[j];
    }else{
      pointArr[j] = max((unsigned long long int)count[j]*j + pointArr[j-2] , pointArr[j-1] );
    }
  }
  return pointArr[i];
}

int main(){
  int NumberOfInputs;
  cin>>NumberOfInputs;
  vector<int> count(100001,0);
  int largest = 0;
  for( int i = 0 ; i < NumberOfInputs ; i++){
    int val;
    cin>>val;
    count[val]++;
    largest = max(largest, val);
  }
  //vector<int> pointA(largest+1,0);
  cout<<maxPoint(largest,count);
}
