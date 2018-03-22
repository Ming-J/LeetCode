#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  string frequencySort(string s){
    vector<int> chr(256,0);
    for(const char c : s){
      ++chr[c];
    }
    auto cmp = [](pair<int,int> lhs, pair<int,int> rhs){
      return lhs.first<rhs.first;
    };
    priority_queue<pair<int,int>, vector<pair<int,int> >,decltype(cmp)> q(cmp);
    for(size_t i = 0; i < chr.size(); ++i){
      if(chr[i] > 0){
	q.push(make_pair(chr[i],i));
      }
    }
    string str;
    while(!q.empty()){
      for( int i = 0; i < q.top().first; ++i){
	str += static_cast<char>(q.top().second);
      }
      q.pop();
    }
    return str;
  }
};

int main(){
  Solution test;
  cout<<test.frequencySort("Aabb");
}
