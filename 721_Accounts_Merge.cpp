#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//Creating a quick union fold
class QF{
public:
  QF(int n){
    id.assign(n,0);
    for(int i=0; i < n; ++i){
      id[i] = i;
    }
  }
  int root(int i){
    while(i != id[i]){
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }
  //Checking to see if the two points has same root
  bool find(int p, int q){
    return root(p)==root(q);
  }
  void unite(int p, int q){
    int i = root(p);
    int j = root(q);
    id[i] = j;
  }
private:
  vector<int> id;
};

class Solution{
public:
  vector<vector<string> > accountsMerge(vector<vector<string> >& accounts){
    vector< vector<string> > res;
    QF unionFind(accounts.size());
    for(size_t i = 0; i < accounts.size(); ++i){
      for(size_t j = 0; j < i; ++j){
	if(!unionFind.find(i,j)){
	  for(size_t k = 1; k < accounts[i].size(); ++k){
	    for(size_t t = 1; t < accounts[j].size(); ++t){
	      if(accounts[i][k] == accounts[j][t]) unionFind.unite(i,j);
	    }
	  }
	}
      }
    }

    vector< set<string> > emails;
    vector<int> roots(accounts.size());
    emails.resize(accounts.size());
    for(size_t i = 0; i < emails.size(); ++i){
      roots[i] = unionFind.root(i);
      for(size_t j = 1; j < accounts[i].size(); ++j){
	emails[roots[i]].insert(accounts[i][j]);
      }
    }
    
    for(size_t i = 0; i < accounts.size(); ++i){
      if(roots[i] == i){
	vector<string> cur;
	cur.push_back(accounts[i][0]);
	for( auto ema : emails[i] ) cur.push_back(ema);
	res.push_back(cur);
      }
    }
    return res;
  }
};

