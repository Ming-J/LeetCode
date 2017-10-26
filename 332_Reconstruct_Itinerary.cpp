#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
    if(n==iternery.size()){
      for(int i=0;i<iternery.size();i++){
	cout<<iternery[i]<<endl;
      }
      return;
    }else{
      if(hash.find(departure)!=hash.end()){
	cout<<dep<<endl;
        for(int i=0;i<hash[departure].size();i++){
	  string arrival=hash[departure][i];
	  hash[departure].erase(hash[departure].begin()+i);
	  iternery.push_back(arrival);
	  dfs(iternery,hash,n,arrival);
	  iternery.pop_back();
	  hash[departure].insert(hash[departure].begin()+1,arrival);
	}
      }else{
	return;
      }
    }
  }
};
