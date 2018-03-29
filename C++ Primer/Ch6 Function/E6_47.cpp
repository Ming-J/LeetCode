#include <iostream>
#include <vector>
using namespace std;

/*
  To turn off debugging, uncomment the following line, or compile the
  program with '-D NDEBUG' switch
*/

void printvectorRec(vector<int>::iterator first, vector<int>::iterator last){
  #ifndef NDEBUG
  cerr<<__FILE__<<' '<<__DATE__<<' '<<__TIME__<<' '<<__func__<<endl;
  #endif
  if( first != last){
    cout<<*first<<endl;
    printvectorRec(++first,last);
  }
  
}

int main(){
  vector<int> vec = {1,2,3,4,5,6,7,8};
  printvectorRec(vec.begin(),vec.end());
}
