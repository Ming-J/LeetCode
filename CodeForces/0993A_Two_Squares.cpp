#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
  int x1,x2,x3,x4,y1,y2,y3,y4;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
  unordered_set< string > points;
  int p1x,p1y,p2x,p2y;
  p1x = min(x1,min(x2,min(x3,x4)));
  p1y = min(y1,min(y2,min(y3,y4)));
  p2x = max(x1,max(x2,max(x3,x4)));
  p2y = max(y1,max(y2,max(y3,y4)));
  for(int i = p1x; i <= p2x; ++i){
    for(int j = p1y; j <= p2y; ++j){
      points.insert(to_string(i) +'_'+ to_string(j));
    }
  }
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
  p1x = min(x1,min(x2,min(x3,x4)));
  p1y = min(y1,min(y2,min(y3,y4)));
  p2x = max(x1,max(x2,max(x3,x4)));
  p2y = max(y1,max(y2,max(y3,y4)));
  int midx = (p1x + p2x)/2;
  int midy = (p1y + p2y)/2;
  int count = 0;
  for(int i = p1y, dif = 0; i < midy; ++i,++dif){
    for(int j = midx-dif; j <= midx+dif; ++j){
      if(points.find(to_string(j)+'_'+to_string(i))!=points.end()){
	++count;
      }
    }
  }
  for(int i = p2y, dif = 0; i >= midy; --i,--dif){
    for(int j = midx-dif; j >= midx+dif; --j){
      if(points.find(to_string(j)+'_'+to_string(i))!=points.end()){
	++count;
      }
    }
  }
  if(count>0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
