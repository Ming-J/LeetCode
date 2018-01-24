#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int main(){

  int lantern = 0;
  int length = 0; 
  cin>>lantern>>length;
  vector<int> pos;
  for(int i = 0 ; i < lantern ; i++){
    int cord;
    cin>>cord;
    pos.push_back(cord);
  }
  sort(pos.begin(),pos.end());
  int diff = INT_MIN;
  for( int i = 1; i < pos.size(); i++){
    diff = max( diff, pos[i] - pos[i-1]); 
  }
  int head = pos[0] - 0;
  int tail = length - pos[pos.size()-1];
  double radius=max(head,tail);
  radius = max( diff/2.0,radius);
  cout<<setprecision(30)<<radius<<endl;
}
