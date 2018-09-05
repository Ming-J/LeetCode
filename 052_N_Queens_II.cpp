#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int totalNQueens(int n) {
    count = 0;
    col.assign(n,false);
    dia.assign(2*n-1,false);
    antiDia.assign(2*n-1,false);
    backtracking(0,n);
    return count;
  }

  void backtracking(int r, int n){
    if(r==n){
      ++count;
      return;
    }
    for(int c = 0; c < n; ++c){
      int iDia = convertDia(r,c);
      int iAnti = convertAnti(r,c);
      if(!col[c]&&!dia[iDia]&&!antiDia[iAnti]){
	col[c] = true ; dia[iDia] = true ; antiDia[iAnti] = true;
	backtracking(r+1,n);
	col[c] = false; dia[iDia] = false; antiDia[iAnti] = false;
      }
    }
  }
  
private:
  vector<bool> col;
  vector<bool> dia;
  vector<bool> antiDia;
  int count = 0;
  int convertDia(int r, int c){
    return r+c;
  }
  int convertAnti(int r, int c){
    //return antiDia.size()-1-(r+c);
    return r+antiDia.size()-1-c;
  }
};

int main(){
  Solution test;
  cout<<test.totalNQueens(4)<<endl;
}
