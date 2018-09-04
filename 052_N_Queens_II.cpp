class Solution {
public:
  int totalNQueens(int n) {
    col.assign(n.false);
    dia.aggisn(2*n-1,false);
    antiDia.assign(2*n-1,false);
    cout<<convert(
  }
private:
  vector<bool> col;
  vector<bool> dia;
  vector<bool> antiDia;

  int convertDia(int r, int c){
    return r+c;
  }

  int convertAnti(int r, int c){
    return antiDia.size()-1-(r+c);
  }
  
};
