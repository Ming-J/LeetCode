#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
    vector<int> ans;
    if(matrix.size()==0||matrix[0].size()==0){
      return ans;
    }
    int colB=matrix[0].size(),rowB=matrix.size();
    int msize=colB*rowB;
    int col=0, row=0;
    bool up=true;
    while(ans.size()!=msize){
      if(row>=0&&row<rowB&&col>=0&&col<colB){
	ans.push_back(matrix[row][col]);
	if(up){
	  //going up diagonal
	  if(col==colB-1){
	    up=false;
	    row++;
	  }else if(row==0){
	    up=false;
	    col++;
	  }else{
	    row--;
	    col++;
	  }
	}else{
	  //going down diagonal
	  if(row==rowB-1){
	    up=true;
	    col++;
	  }else if(col==0){
	    up=true;
	    row++;
	  }else{
	    row++;
	    col--;
	  }
	}
      }
    }
    return ans;
  } 
};
