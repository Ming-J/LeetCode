#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
      vector<string> ans;
      unordered_map<string,vector<string> > hash;
      for(int i=0;i<tickets.size();i++){
	hash[tickets[i].first].push_back(tickets[i].second);
      }
      for(auto i=hash.begin();i!=hash.end();i++){
	sort(i->second.begin(),i->second.end());
      }
      string dep="JFK";
      ans.push_back(dep);
      dfs(ans,hash,tickets.size()+1,dep);
      return ans;
    }
  void dfs(vector<string>& iternery,
	   unordered_map<string,vector<string> >& hash,
	   int n, string departure){
    vector<string> circuit;
    while(iternery.size()+circuit.size()!=n){
      if(hash.find(departure)!=hash.end()){
	string arrival=*hash[departure].begin();
	iternery.push_back(arrival);
	hash[departure].erase(hash[departure].begin());
	departure=arrival;
      }else{
	string arr=iternery.back();
	while(hash[arr].size()==0){
	  iternery.pop_back();
	  circuit.push_back(arr);
	  arr=iternery.back();
	}
	departure=arr;
      }
    }
    circuit.insert(circuit.end(),iternery.rbegin(),iternery.rend());
    iternery.clear();
    iternery.insert(iternery.end(),circuit.rbegin(),iternery.rend());
  }
};
