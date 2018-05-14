#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> output((n+1)*2-1,string((n*2)*2+1,' '));
  for(int lo = 0, hi = output.size() -1; lo <= hi; ++lo,--hi){
    int front = n*2;
    int back = n*2;
    for(int j = lo; j >= 0; --j){
      char val = j + '0';
      output[lo][front] = val;
      output[lo][back] = val;
      output[hi][front] = val;
      output[hi][back] = val;
      front -= 2;
      back += 2;
    }
    output[lo].erase(output[lo].begin()+back-1,output[lo].end());
    output[hi].erase(output[hi].begin()+back-1,output[hi].end());
  }
  for(auto i : output){
    cout<<i<<endl;
  }
}
