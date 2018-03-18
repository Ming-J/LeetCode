#include <iostream>
#include <vector>
using namespace std;
/*
  Idea is toating the matrix layer by layer.  
  Starting with the Corner, figure out the first and last for the
  current layers and just rotate the top row.
  rotatbleLayer = matrix.size() / 2
  first = i;
  last = matrix.size() - i - 0
*/
class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    int rotatableLayer = matrix.size()/2;
    for(size_t i = 0; i < rotatableLayer; ++i){
      int first = i;
      int last = matrix.size() - i - 1;
      for(size_t j = 0; j < (last - first); ++j){ 
	int topLeft = matrix[first][first+j];
	int topRight = matrix[first+j][last];
	int botLeft = matrix[last-j][first];
	int botRight = matrix[last][last-j];
	matrix[first][first+j] = botLeft;
	matrix[first+j][last] = topLeft;
	matrix[last-j][first] = botRight;
	matrix[last][last-j] = topRight;
      }
    }
  }
  void print(const vector<vector<int> >& m){
    for(const auto r: m){
      for(const auto i: r){
	cout<<i<<' ';
      }
      cout<<endl;
    }
  }
};

int main(){
  vector< vector<int> > m = {{2,29,20,26,16,28}
			     ,{12,27,9,25,13,21}
			     ,{32,33,32,2,28,14}
			     ,{13,14,32,27,22,26}
			     ,{33,1,20,7,21,7},
			     {4,24,1,6,32,34}};
  Solution test;
  test.print(m);
  test.rotate(m);
  cout<<endl;
  test.print(m);
}
