#include <iostream>
#include <vector>
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
  void helper(vector< vector<int> >& ans, vector<int> current, int fixed){
    if(fixed==current.size()-1){
      ans.push_back(current);
    }
    for(int i=fixed;i<current.size();i++){
      swap(current,fixed,i);
      helper(ans,current,fixed+1);
    }
  }
  vector< vector<int> > permute(vector<int>& nums) {
      vector< vector<int> > result;
      helper(result,nums,0);
      return result;
    }
};

int main(){
  cout<<"Hello world"<<endl;
}
