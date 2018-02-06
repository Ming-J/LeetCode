#include <iostream>
#include <vector>
using namespace std;

vector<int> calWalk(vector<int> &aff, int walkNeed, int &newWalks){
  vector<int> walks(aff.size(),0);
  walks[0] = aff[0];
  for( int i = 1; i < aff.size(); i++){
    int affSum = aff[i] + walks[i-1];
    int additional = ( walkNeed - affSum > 0 )? walkNeed - affSum : 0;
    newWalks += additional;
    walks[i] = aff[i] + additional;
  }
  return walks;
}

int main(){
  int days = 4, walksNeed = 6;
  cin >> days >> walksNeed;
  vector<int> aff(days,0);
  for(int i = 0; i < days; i++){
    cin >> aff[i];
  }
  int sum = 0;
  vector<int> dp = calWalk(aff,walksNeed,sum);
  cout<<sum<<endl;
  for( int i : dp ){
    cout<<i<<' ';
  }
}
