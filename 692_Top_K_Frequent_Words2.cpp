#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

bool sortpair(pair<string,int> le,pair<string,int> ri){
    if(ri.second==le.second){
      int com=le.first.compare(ri.first);
      if(com>0){
        return false;
      }else{
        return true;
      }
    }else{
      return le.second>ri.second;
    }
  }
class Solution{
public:
  vector<string> topKFrequent(vector<string>& words,int k){
    map<string,int> heaphash;


    unordered_map<string,int> hash;
    for(int i=0;i<words.size();i++){
      hash[words[i]]++;
    }
    vector<pair<string,int> > v;
    for(auto i=hash.begin();i!=hash.end();i++){
      v.push_back(make_pair(i->first,i->second));
    }
    sort(v.begin(),v.end(),sortpair);
    vector<string> ans;
    for(int i=0;i<k;i++){
      ans.push_back(v[i].first);
    }
    return ans;
  }
};
