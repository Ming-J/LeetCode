#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;

class Solution {
public:
    string findReplaceString(string S,
			     vector<int>& indexes,
			     vector<string>& sources,
			     vector<string>& targets) {
      if(indexes.size() == 0) return S;
      vector< tuple<int,string,string> > combine;
      for(size_t i = 0; i < indexes.size(); ++i){
	combine.push_back(make_tuple(indexes[i],sources[i],targets[i]));
      }
      sort(combine.begin(),combine.end(),greater<tuple<int,string,string>>());
      for(auto tu : combine){
	cout<<get<0>(tu)<<endl;
	if(S.substr(get<0>(tu),(get<1>(tu)).size()) == get<1>(tu)){
	  S.replace(get<0>(tu),(get<1>(tu)).size(),get<2>(tu));
	}
      }
      return S;
    }
};

int main(){
  vector<int> ind = {0,2};
  vector<string> sou = {"ab","ec"};
  vector<string> tar = {"eee","fff"};
  string S = "abcd";
  Solution t;
  cout<<t.findReplaceString(S,ind,sou,tar)<<endl;
}
