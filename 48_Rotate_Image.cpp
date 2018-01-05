#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void rotate(vector<vector<int> >& matrix){
    if(matrix.size()==0||matrix[0].size()==0){
      return;
    }
    int height = matrix.size();
    int length = matrix[0].size();

    if(height != length){
      return;
    }
    int temp=0;

    for(int i=0; i<height/2; i++){
      for(int j=i; j<height-1-i;j++){
	temp = matrix[i][j];
	matrix[height-j-1][i] = matrix[height-i-1][height-j-1];
	matrix[height-j-1][height-j-1] = matrix[j][height-i-1];
	matrix[j][height-i-1]=temp;
      }
    }
  }
};
