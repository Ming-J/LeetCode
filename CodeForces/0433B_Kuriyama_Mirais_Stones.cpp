#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Stones{
public:
  Stones(vector<unsigned long long int> c):cost{0},sort_cost{0}{
    cost.insert(cost.end(),c.begin(),c.end());
    sort_cost.insert(sort_cost.end(),c.begin(),c.end());
    sort(sort_cost.begin(),sort_cost.end());
    partial_sum(cost.begin(),cost.end(),cost.begin());
    partial_sum(sort_cost.begin(),sort_cost.end(),sort_cost.begin());
  }
  unsigned long long int getSum(int type, int lo, int hi){
    lo = lo-1;
    if(type == 1) return cost[hi] - cost[lo];
    else return sort_cost[hi] - sort_cost[lo];
  }  
private:
  vector<unsigned long long int> cost;
  vector<unsigned long long int> sort_cost;
};

int main(){
  int n;
  cin>>n;
  vector<unsigned long long int> input(n);
  for(auto& s : input) cin>>s;
  cin>>n;
  Stones mira(input);
  for(int i = 0; i < n; ++i){
    int type, lo, hi;
    cin>>type>>lo>>hi;
    cout<<mira.getSum(type,lo,hi)<<endl;
  }
}
