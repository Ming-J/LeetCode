#include <iostream>
#include <vector>
using namespace std;

class NumMatrix{
private:
  vector< vector<int> >sumMatrix;
public:
  NumMatrix(vector<vector<int> > matrix) {
    if(matrix.size()==0||matrix[0].size()==0){
      return;
    }
    sumMatrix.assign(matrix.size(),vector<int> (matrix[0].size(),0));
    for(int i=0;i<matrix.size();i++){
      for(int j=0;j<matrix[i].size();j++){
	if(i==0&&j==0){
	  sumMatrix[i][j]=matrix[i][j];
	}else if(i==0){
	  sumMatrix[i][j]=matrix[i][j]+sumMatrix[i][j-1];
	}else if(j==0){
	  sumMatrix[i][j]=matrix[i][j]+sumMatrix[i-1][j];
	}else{
	  sumMatrix[i][j]=matrix[i][j]+
	    sumMatrix[i][j-1]+sumMatrix[i-1][j]-sumMatrix[i-1][j-1];
	}
      }
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum=0;
    if(row1==0&&col1==0){
      sum=sumMatrix[row2][col2];
    }else if(row1==0){
      sum=sumMatrix[row2][col2]-sumMatrix[row2][col1-1];
    }else if(col1==0){
      sum=sumMatrix[row2][col2]-sumMatrix[row1-1][col2];
    }else{
      sum=sumMatrix[row2][col2]-
	sumMatrix[row2][col1-1]-sumMatrix[row1-1][col2]+
	sumMatrix[row1-1][col1-1];
    }
    
    return sum;
  }
};
