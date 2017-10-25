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
      while(!hash.empty()){
	string arr=hash[dep][0];
	hash[dep].erase(hash[dep].begin());
	if(hash[dep].size()==0){
	  hash.erase(dep);
	}
	ans.push_back(arr);
	dep=arr;
      }
      for(int i=0;i<ans.size();i++){
	cout<<ans[i]<<endl;
      }
      for(auto i=hash.begin();i!=hash.begin();i++){
	for(int j=0;j<hash[i->first].size();j++){
	  cout<<i->first<<" "<<hash[i->first][j]<<endl;
	}
      }
      return ans;
    }
};
