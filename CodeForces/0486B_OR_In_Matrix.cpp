#include <iostream>
#include <vector>
using namespace std;

class M{
public:
  M(vector<vector<int>> m):matrix(m){}

  bool calculate(){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m,1);
    vector<int> col(n,1);
    bool one = false;
    for(int i = 0; i < m; ++i){
      for(int j = 0; j < matrix[i].size(); ++j){
	if(matrix[i][j] == 1) one =true;
	row[i] &= matrix[i][j];
      }
    }
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < matrix.size(); ++j){
	col[i] &= matrix[j][i];
      }
    }
    bool one2 = false;
    original.assign(m,vector<int>(n,1));
    vector<vector<int>> result(m,vector<int>(n,0));
    for(int i = 0; i < original.size(); ++i){
      for(int j = 0; j < original[i].size(); ++j){
	original[i][j] = row[i]&col[j];
	if(original[i][j] == 1){
	  result[i].assign(n,1);
	  for(auto& row: result) row[j] = 1;
	}
      }
    }
    return result==matrix;
  }

  void print(){
    for(auto r : original){
      for(auto i : r){
	cout<<i<<' ';
      }
      cout<<endl;
    }
  }

private:
  vector<vector<int> > matrix;
  vector<vector<int>> original;
};



int main(){
  int m, n;
  cin>>m>>n;
  vector<vector<int> > input(m,vector<int>(n));
  for(auto& row : input){
    for(auto& i : row){
      cin>>i;
    }
  }
  M matrixB(input);
  matrixB.print();
  if(matrixB.calculate()){
    cout<<"YES"<<endl;
    matrixB.print();
  }else{
    cout<<"NO"<<endl;
  }
}
