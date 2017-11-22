#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution{
public:
  int numberOfBoomerangs(vector< pair<int, int> >& points){
    int boom=0;
    for(size_t i=0;i<points.size();i++){
      int count=0;
      unordered_map<int,int> distantMap;
      while(count<points.size()){
	if(i!=count){
	  int x1=points[i].first;
	  int y1=points[i].second;
	  int x2=points[count].first;
	  int y2=points[count].second;
	  int distance=pow(x2-x1,2)+pow(y2-y1,2);
	  distantMap[distance]++;
	}
	count++;
      }
      for(auto j=distantMap.begin();j!=distantMap.end();j++){
	if(j->second>1){
	  int combo=j->second*(j->second-1);
	  boom+=combo;
	}
      }
    }
    return boom;
  }
};
