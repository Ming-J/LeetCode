#include <iostream>
using namespace std;

/*
  Gardens are squres, parallel to coordinate axes
  x1, x2, y1, y2
  -1, for no solutions
*/

int main(){
  //inputs
  int x1,y1, x2, y2;
  cin>>x1>>y1>>x2>>y2;
  //check to see if the two points are next to or adjection to
  int x3,y3,x4,y4;
  int deltaX = abs(x1-x2);
  int deltaY = abs(y1-y2);
  if(x1==x2){
    x3 = x4 = x1+deltaY;
    y3 = y1;
    y4 = y2;
  }else if(y1==y2){
    y3 = y4 = y1 + deltaX;
    x3 = x1;
    x4 = x2;
  }else if(deltaX == deltaY){
    //adjecten
    x3 = x1;
    y3 = y2;
    x4 = x2;
    y4 = y1;
  }else{
    cout<<-1<<endl;
    return 0;
  }
  cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}
