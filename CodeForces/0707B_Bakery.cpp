#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <tuple>
using namespace std;

class Bakery{
public:
  Bakery(int c, vector<int> f,
	 vector<tuple<int,int,unsigned long> > ro){
    city_num = c;
    for(auto& i : f) flour.insert(i);
     unsigned long path = numeric_limits<unsigned long>::max();
    for(auto& tu : ro){
      int c1 = get<0>(tu);
      int c2 = get<1>(tu);
      unsigned long length = get<2>(tu);
      auto check1 = flour.find(c1);
      auto check2 = flour.find(c2);
      if( (check1 != flour.end() && check2 == flour.end()) ||
	  (check1 == flour.end() && check2 != flour.end())){
	  path = min(path,length);
      }
    }
    min_path = path==numeric_limits<unsigned long>::max()?-1:path;
  }

  long int openBakery(){
    return min_path;
  }

private:
  int city_num;
  unordered_set<int> flour;
  long int min_path;
};


int main(){
  int n, m, k;
  cin>>n>>m>>k;
  vector<tuple<int,int,unsigned long>> path(m);
  for(auto& t : path){
    int v, u;
    unsigned long l;
    cin>>v>>u>>l;
    t = make_tuple(v,u,l);
  }
  vector<int> flour(k);
  for(auto& f : flour) cin>>f;
  Bakery b(n,flour,path);
  path.clear();
  flour.clear();
  cout<<b.openBakery()<<endl;
}
