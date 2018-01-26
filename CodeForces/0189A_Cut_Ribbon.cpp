#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n , a, b , c;
  cin>>n>>a>>b>>c;

  vector<int> maxPiece (n+1,0);

  maxPiece[0] = 0;

  for( int i = 1 ; i < n+1 ; i ++ ){
    int x=-1,y=-1,z=-1;
    if ( i-a >= 0 ){
      x = maxPiece[ i - a ];
    }
    if ( i-b >= 0 ){
      y = maxPiece[ i - b ];
    }
    if ( i-c >= 0 ){
      z = maxPiece[ i - c ];
    }
    if ( x == -1 && y == -1 && z == -1){
      maxPiece[i] = -1;
    }else{
      maxPiece[i] = max( x , max(y , z) )+1;
    }
  }
  cout<<maxPiece[n]<<endl;
}
