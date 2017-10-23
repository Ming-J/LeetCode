#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<string> topKFrequent(vector<string>& words,int k){
    unordered_map<string,int> hash;
    for(int i=0;i<words.size();i++){
      hash[words[i]]++;
    }
    vector<pair<string,int> > v;
    for(auto i=hash.begin();i!=hash.end();i++){
      v.push_back(make_pair(i->first,i->second));
    }
  }
  bool sortpair(pair<string,int> ri,pair<string,int> le){
    if(ri.second==le.second)
  }
  
};
