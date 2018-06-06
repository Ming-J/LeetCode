#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  string input;
  cin>>input;
  vector<int> black;
  int count = 0;
  for(size_t i = 0; i < input.size(); ++i){
    if(input[i] == 'B'){
      ++count;
    }else{
      if(count != 0){
	black.push_back(count);
	count = 0;
      }
    }
  }
  if(count != 0) black.push_back(count);
  cout<<black.size()<<endl;
  for(auto c: black){
    cout<<c<<' ';
  }
}
