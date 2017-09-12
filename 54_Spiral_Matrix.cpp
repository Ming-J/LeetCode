#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  //previous=1 Going right  2=Going down, 3=Going left, 4=Going Left
  void spiralOrderHelp(vector<vector<int> >& matrix,
		       vector< vector<bool> >&  visited,
		       int row, int col,int& previous,
		       vector<int>& ans){
    if(row<0||col<0||row==matrix.size()||col==matrix[0].size()||visited[row][col]==true){
      if(ans.size()==matrix.size()*matrix[0].size()){
	return;
      }
      if(previous==1){
	previous=2;
      }else if(previous==2){
	previous=3;
      }else if(previous==3){
	previous=4;
      }else{
	previous=1;
      }
    }else{
      visited[row][col]=true;
      ans.push_back(matrix[row][col]);
      while(ans.size()!=matrix.size()*matrix[0].size()){
        if(previous==1){
	spiralOrderHelp(matrix, visited, row, col+1, previous, ans);
      }
      if(previous==2){
	spiralOrderHelp(matrix, visited, row+1, col, previous, ans);
      }
      if(previous==3){
	spiralOrderHelp(matrix, visited, row, col-1, previous, ans);
      }
      if(previous==4){
	spiralOrderHelp(matrix, visited, row-1, col, previous, ans);
      }
    }
    }
  }
  vector<int> spiralOrder(vector<vector<int> >& matrix) {
      vector<int> ans;
      if(matrix.size()==0||matrix[0].size()==0){
	return ans;
      }
      vector<bool> r(matrix[0].size(),false);
      vector< vector<bool> > visited(matrix.size(), r);
      int motion=1;
      spiralOrderHelp(matrix, visited, 0, 0, motion, ans);
      return ans;
    }
};
int main(){
  cout<<"Hello World"<<endl;
}
