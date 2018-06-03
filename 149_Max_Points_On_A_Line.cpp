#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <limits>
#include <algorithm>
using namespace std;

/*
Go throught every point and using slope to see if lines are in the
same line.  We use hash map to store the slope, however due to the
precision, we will have to use pair to store slope.
BY storing them in pairs, need to reduce their factors

Few exception:

When the two points are at the same, we would have to increase all the
points store by one

When line are horz, or vertical
*/
struct Point{
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution{
public:
  int maxPoints(vector<Point>& points){
    if(points.size()<2) return points.size();
    int maxP = 0;
    for(size_t i = 0; i < points.size(); ++i){
      unordered_map<string, int> slopes;
      int lineP = 0;
      int sameP = 0;
      for(size_t j = i+1; j < points.size(); ++j){
	if(points[i].x == points[j].x && points[i].y == points[j].y) ++sameP;
	else{
	  pair<int,int> s = calSlope(points[i].x,points[i].y,points[j].x,points[j].y);
	  string slp = to_string(s.first) + '/' + to_string(s.second);
	  ++slopes[slp];
	  lineP = max(lineP, slopes[slp]);
	}
      }
      lineP += sameP;
      maxP = max(maxP,lineP);
    }
    return maxP+1;
  }
private:
  int gcd(int a, int b){
    return (b==0)? a : gcd(b, a%b);
  }
  pair<int,int> calSlope(int x1, int y1, int x2, int y2){
    int deltaX = x1 - x2;
    int deltaY = y1 - y2;
    if(deltaX == 0) return pair<int,int>(numeric_limits<int>::max(),0);
    if(deltaY == 0) return pair<int,int>(numeric_limits<int>::min(),0);
    int div = gcd(deltaX,deltaY);
    return pair<int,int>(deltaX/div,deltaY/div);
  }
};
