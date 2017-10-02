#include <iostream>
#include <vector>
using namespace std;

class matrix{
private:
  vector< vector<int> > m;
public:
  matrix(int ro, int cl){
    for(int i=0;i<ro;i++){
      vector<int> row(cl,0);
      m.push_back(row);
    }
  }
  void operation(int a, int b){
    for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
	m[i][j]++;
      }
    }
  }

  int countmax(){
    int max=0;
    int count;
    for(int i=0;i<m.size();i++){
      for(int j=0;j<m[i].size();j++){
	if(m[i][j]==max){
	  count++;
	}
	if(m[i][j]>max){
	  max=m[i][j];
	  count=0;
	}
      }
    }
    return count;
  }
  
  void print(){
    for(int i=0;i<m.size();i++){
      for(int j=0;j<m[i].size();j++){
	cout<<m[i][j];
      }
      cout<<endl;
    }
  }
};

class Solution{
public:
  int maxCount(int m, int n, vector<vector<int> >& ops){
    if(ops.size()==0){
      return m*n;
    }
    if(ops.size()==1){
      return ops[0][0]*ops[0][1];
    }
    int row=m;
    int col=n;
    int area=m*n;
    for(int i=0;i<ops.size();i++){
      row=min(ops[i][0],row);
      col=min(ops[i][1],col);
      area=min(area,row*col);
      //ma.operation(ops[i][0],ops[i][1]);
    }
    //ma.print();
    return area;
  }
};
