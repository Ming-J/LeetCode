#include <iostream>
#include <vector>
using namespace std;


int main(){
  int x;
  cin>>x;
  int c = 0;
  vector< vector<char> > board(x,vector<char> (x,'.'));
  for(int i = 0; i < x; ++i){
    bool mask = i%2==0?true:false;
    for(int j = 0; j < x; ++j){
      if(mask){
	board[i][j] = 'C';
	++c;
      }
      mask ^= true;
    }
  }
  cout<<c<<endl;
  for(auto i:board){
    for(auto c:i){
      cout<<c;
    }
    cout<<endl;
  }
}
