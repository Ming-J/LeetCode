#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

/* Test Case : {{0,0},{0,0},{0,0},{0,0}}
 * The reason to validPoints few times are for the test case, just to p1
*/
class Solution {
public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    return validPoints(p2,p1,p3,p4)&&validPoints(p3,p1,p2,p4)&&validPoints(p4,p1,p3,p2)
  }
  //Checking the distance from p1 to other points, two of them have to
  //be the same, the larger one need to be the smaller one * 2
  bool validPoints(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
    vector<int> dAllPoints = {distance(p1,p2),distance(p1,p3),distance(p1,p4)};
    sort(dAllPoints.begin(),dAllPoints.end());
    if(dAllPoints[0] == dAllPoints[1] && dAllPoints[2] == dAllPoints[0] * 2 && dAllPoints[2] > dAllPoints[0]){
      return true;
    }
    return false;
  }

  //Calculating the distance between two points
  int distance(vector<int>& p1, vector<int>& p2){
    return pow(p2[0] - p1[0],2) + pow(p2[1] - p1[1],2);
  }
};

int main(){
  vector<int> p1 = {-10000, -10000};
  vector<int> p2 = {-10000, 10000};
  vector<int> p3 = {10000, 10000};
  vector<int> p4 = {10000, -10000};
  Solution test;
  if(test.validSquare(p1, p2, p3, p4)){
    cout<<"It's a square"<<endl;
  }else{
    cout<<"Not a square"<<endl;
  }
}
