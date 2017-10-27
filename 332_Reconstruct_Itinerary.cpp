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
      /*for(int i=0;i<ans.size();i++){
	cout<<ans[i]<<endl;
	}*/
      for(auto i=hash.begin();i!=hash.end();i++){
	for(int j=0;j<hash[i->first].size();j++){
	  cout<<i->first<<" "<<hash[i->first][j]<<endl;
	}
      }
      return ans;
    }
  void dfs(vector<string>& iternery,
	   unordered_map<string,vector<string> >& hash,
	   int n, string departure){
    //stack<string> deck;
    //deck.push(arrival);
    while(!hash.empty()){
      if(hash.find(departure)!=hash.end()){
	string arrival=*hash[departure].begin();
	iternery.push_back(arrival);
	hash[departure].erase(hash[departure].begin());
	departure=arrival;
      }else{
	string arr=iternery.back();
	iternery.pop_back();
	string dep=iternery.back();
	hash[dep].push_back(arr);
      }
    }
  }
};
