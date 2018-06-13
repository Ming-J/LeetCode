#include <iostream>
#include <map>
using namespace std;
/*
 n number of stewards
 one steard < john < obe steward
 
 go through the array, exclude the front and the back .

 However if the array is all the same, we can not support.
 
 creating a map to store the strength in order, excluding the smallest
 and largest. 

# of stwards - # of small strength - # of argest strength = # able to help

*/
int main(){
  int stewards;
  cin>>stewards;
  map<int,int> treeSet;
  for(int i = 0; i < stewards; ++i){
    int n;
    cin>>n;
    ++treeSet[n];
  }
  int num = stewards - treeSet.begin()->second - (--treeSet.end())->second;
  num = (num>0)?num:0;
  cout<<num<<endl;
}
