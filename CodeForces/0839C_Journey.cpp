#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
using namespace std;
/*
  n cities  n-1 roads
*/

class Kingdoms{
public:
  Kingdoms(int n):cities{n}{
    roads.assign(n,vector<int>());
  }
  void connect(int c1, int c2){
    roads[c1-1].push_back(c2-1);
    roads[c2-1].push_back(c1-1);
  }

  long double cal(int cur, int from){
    long double dis = 0.0;
    for(auto going_to : roads[cur]){
      if(going_to != from)
	dis += cal(going_to,cur) + 1;
    } 
    return dis ? dis/(roads[cur].size() - (from != -1) ) : 0;
  }

private:
  int cities;
  vector< vector<int> > roads;
};



int main(){
  int n;
  cin>>n;
  Kingdoms seven(n);
  for(int i = 1; i < n; ++i){
    int c1,c2;
    cin>>c1>>c2;
    seven.connect(c1,c2);
  }
  cout<<fixed<<setprecision(7)<<seven.cal(0,-1)<<endl;;
}
