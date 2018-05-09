#include <iostream>
#include <unordered_set>
using namespace std;

double calSlope(int x1, int y1, int x2, int y2){
  return (x2-x1!=0)?
    static_cast<double>(y2 - y1)/static_cast<double>(x2 - x1):INT_MAX;
}

int main(){
  int n, gx, gy;
  cin>>n>>gx>>gy;
  unordered_set<double> slopes;
  for(int i = 0; i < n; ++i){
    int x,y;
    cin>>x>>y;
    slopes.insert(calSlope(gx,gy,x,y));
  }
  cout<<slopes.size()<<endl;
}
