#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
  int student=0, puzzle=0;
  vector<int> puzzlePrice;
  cin>>student>>puzzle;
  int pr;
  for( int i = 0; i< puzzle ; i++){
    cin>>pr;
    puzzlePrice.push_back(pr);
  }
  sort(puzzlePrice.begin(),puzzlePrice.end());
  int lo = 0;
  int minDiff = INT_MAX;
  for( int hi = student -1 ; hi < puzzlePrice.size() ; hi++){
    minDiff = min( minDiff, puzzlePrice[hi] - puzzlePrice[lo] );
    lo++;
  }
  cout<<minDiff<<endl;
  return 0;
}
