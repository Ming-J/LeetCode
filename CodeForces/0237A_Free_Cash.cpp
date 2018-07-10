#include <iostream>
#include <map>
using namespace std;

/*
  n ppl will visiited
  i ppl will be at h_i hour and m_i minute
  less than a minute to serve each client

  Get the most profit, ensure that at each moment of time the number
  of working caches is no less thatn the number of clients in the
  cafe.

  count the minimum number of cashes to work at his cafe next days.
  so that they can serve all visitors.

*/

int main(){
  int n;
  cin>>n;
  int h, m;
  int cash = 0;
  map< pair<int,int> , int> hash;
  for(int i = 0; i < n; ++i){
    cin>>h>>m;
    pair<int,int> p = make_pair(h,m);
    map< pair<int,int>,int >::iterator it = hash.find(p);
    if(it == hash.end()){
      hash.insert(make_pair(p,1));
      cash = max(cash, 1);
    }else{
      cash = max(cash,++(it->second));
    }
  }
  cout<<cash<<endl;
}
