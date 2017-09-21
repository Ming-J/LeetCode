#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  void swap(vector<int>& num, int r, int l){
    if(r<num.size()&&l<num.size()){
      int temp=num[r];
      num[r]=num[l];
      num[l]=temp;
    }
  }
  void helper(set< vector<int> >& ans, vector<int> current, int fixed){
    if(fixed==current.size()-1){
      ans.insert(current);
    }
    for(int i=fixed;i<current.size();i++){
      swap(current,fixed,i);
      helper(ans,current,fixed+1);
    }
  }
  vector< vector<int> > permuteUnique(vector<int>& nums) {
      set< vector<int> > result;
      helper(result,nums,0);
      vector<vector<int> > output(result.begin(),result.end());
      return output;
    }
};

int main(){
  cout<<"Hello world"<<endl;
}
