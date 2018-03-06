#include <iostream>
#include <vector>
using namespace std;

void printvectorRec(vector<int>::iterator first, vector<int>::iterator last){
  if( first != last){
    cout<<*first<<endl;
    printvectorRec(++first,last);
  }
}

int main(){
  vector<int> vec = {1,2,3,4,5,6,7,8};
  printvectorRec(vec.begin(),vec.end());
}
