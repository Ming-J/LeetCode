#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > combinationSum(vector<int>& candidates, int target){
    sort(candidates.begin(),candidates.begin()+candidates.size());
    vector<vector<int> > ans;
    vector<int> current;
    backtrack(ans,candidates,current,0,target);
    return ans;
    for(int i=0;i<candidates.size();i++){
      cout<<candidates[i]<<endl;
    }
  }

  void backtrack(vector<vector<int> >& ans,vector<int>& candidates, vector<int>current, int last, int rest){
    //boundry condition
    if(rest==0){
      ans.push_back(current);
    }
    for(int i=last;i<candidates.size()&&candidates[i]<=rest;i++){
      current.push_back(candidates[i]);
      backtrack(ans,candidates,current,i,rest-candidates[i]);
      current.pop_back();
    }
    
  }
  
};

int main(){
  int test[4]={7,3,2,6};
  vector<int> input(begin(test), end(test));
  cout<<"Hello World!"<<endl;
  Solution result;
  vector<vector<int> > ans=result.combinationSum(input,7);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}
