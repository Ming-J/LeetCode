#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  //inputs
  int cities;
  cin>>cities;
  vector<pair<int, int> >pos;
  for(size_t i = 0; i < cities; ++i){
    int c;
    cin>>c;
    pos.push_back(make_pair(c,i));
  }

  sort(pos.begin(),pos.end());
  vector<pair<int,int> > output(cities);

  for(int i = 0; i < pos.size(); ++i){
    int originInd = pos[i].second;
    int curPosition = pos[i].first;
    if(i == 0){
      output[originInd].first = pos[i+1].first - curPosition;
      output[originInd].second = pos.back().first - curPosition;
    }else if(i == pos.size() - 1){
      output[originInd].first = curPosition - pos[i-1].first;
      output[originInd].second = curPosition - pos.front().first;
    }else{
      int neighbor1 = abs(curPosition - pos[i-1].first);
      int neighbor2 = abs(curPosition - pos[i+1].first);
      output[originInd].first = min(neighbor1,neighbor2);
      neighbor1 = abs(curPosition - pos.front().first);
      neighbor2 = abs(curPosition - pos.back().first);
      output[originInd].second = max(neighbor1,neighbor2);
    }
  }
  for(auto p : output) cout<<p.first<<' '<<p.second<<endl;;
}
