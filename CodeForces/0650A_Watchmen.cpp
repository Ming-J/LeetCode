#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
  n watchmen,   ith wachman are at (x_i,y_i)
  0 + 4 = 4
  0 + 4 
*/

class WatchMen{
public:
  WatchMen(){

  }

  void insert(pair<int,int> p ){
    ++sameX[p.first];
    ++sameY[p.second];
    ++same[to_string(p.first) + to_string(p.second)];
  }

  long long int cal(){
    unsigned long long int count = 0;
    for(auto xp : sameX){
      if(xp.second > 1){
	count += (static_cast<unsigned long long int>(xp.second) * (xp.second - 1) ) / 2;
      } 
    }
    for(auto yp : sameY){
      if(yp.second > 1){
	count += (static_cast<unsigned long long int>(yp.second) * (yp.second - 1) ) / 2;
      } 
    }
    for(auto p : same){
      if(p.second > 1){
	count -= (static_cast<unsigned long long int>(p.second) * (p.second - 1) ) / 2;
      } 
    }
    return count;
  }

private:
  unordered_map<long, long> sameX;
  unordered_map<long, long> sameY;
  unordered_map<string , long> same;
};



int main(){
  int n;
  cin>>n;
  vector< pair<long,long> > input(n);
  for(auto& p : input) cin>>p.first>>p.second;
  WatchMen w;
  for(auto p : input) w.insert(p);
  cout<<w.cal()<<endl;
}
