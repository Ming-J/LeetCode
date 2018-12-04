#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  n drives
  m size file
*/

class USB{
public:
  int cal(vector<int> sticks, int fileSize){
    sort(sticks.begin(),sticks.end(),greater<int>());
    int count = 0;
    for(int i = 0;fileSize>0;++i,++count){
      fileSize -= sticks[i];
    }
    return count;
  }
};


int main(){
  int n,size;
  cin>>n>>size;
  vector<int> input(n);
  for(auto& n : input) cin>>n;
  USB temp;
  cout<<temp.cal(input,size)<<endl;
}
