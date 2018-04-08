#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
      int ans=0;
      unordered_map<int,Employee*> hash;
      for(auto e:employees){
	hash[e->id] = e;
      }
      dfs(hash,ans,id);
      return ans;
    }
private:
  void dfs(unordered_map<int,Employee*> hash, int &total, int id){
    total += hash[id]->importance;
    for(auto sub : hash[id]->subordinates){
      dfs(hash,total,sub);
    }
  }
};
