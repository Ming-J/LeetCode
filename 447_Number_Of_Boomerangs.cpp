#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution{
public:
  int numberOfBoomerangs(vector< pair<int, int> >& points){
    int boom=0;
    //iterate all points
    for(size_t i=0;i<points.size();i++){
      int count=0;
      unordered_map<int,int> distantMap;
      //iterate all other points from point[i]
      while(count<points.size()){
	if(i!=count){
	  //calculating distance a^2+b^2=c^2
	  int x1=points[i].first;
	  int y1=points[i].second;
	  int x2=points[count].first;
	  int y2=points[count].second;
	  int distance=pow(x2-x1,2)+pow(y2-y1,2);
	  //accumlate # of points that are "Key" distance from point[i]
	  distantMap[distance]++;
	}
	count++;
      }
      for(auto j=distantMap.begin();j!=distantMap.end();j++){
	if(j->second>1){
	  //for all the group of point selecting 2 from n nP2=n*(n-1)=n!/(n-2)!
	  int combo=j->second*(j->second-1);
	  boom+=combo;
	}
      }
    }
    return boom;
  }
};
