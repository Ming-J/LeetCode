#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<int, int> > laptops;
  for(int i = 0; i < n; ++i){
    int a, b;
    cin>>a>>b;
    laptops.push_back({a,b});
  }
  sort(laptops.begin(),laptops.end());
  string output = is_sorted(laptops.begin(),laptops.end(),
	    [](pair<int,int>& lhs, pair<int,int>& rhs){
			      return lhs.second<rhs.second;})?
    "Poor Alex":"Happy Alex";
  cout<<output<<endl;
  return 0;
}
