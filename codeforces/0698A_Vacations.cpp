#include <iostream>
#include <vector>
using namespace std;
/*
  0: gym closed, contest closed
  1: gym closed, contest open
  2: gym is open, contest is not open
  3: gym open, contest open
  if 0 is R
  
  1 3 2 0
  C G R R
*/


int main(){
  int t;
  cin>>t;
  vector<int> activity(t,0);
  for(size_t i = 0; i < activity.size(); ++i){
    cin>>t;
    activity[i] = t;
  }
  vector<char> task(activity.size(),0);
  for( size_t i = 0; i < activity.size(); ++i){
    if( activity[i] == 0 ){
      task[i] = 'R';
    }else if (activity[i] == 1){
      if( i > 0 and task[i-1] == 'C'){
	task[i] = 'R';
      }else{
	task[i] = 'C';
      }
    }else if( activity[i] == 2){
      if( i > 0 and task[i-1] == 'G'){
	task[i] = 'R';
      }else{
	task[i] = 'G';
      }
    }else{
      if( i > 0 and task[i-1] == 'G'){
	task[i] = 'C';
      }else if( i > 0 and task[i-1] == 'C'){
	task[i] = 'G';
      }else{
	task[i] = 'C';
      }
    }
  }
  int count = 0;
  for(char c : task){
    //cout<<c<<' ';
    if( c == 'R') count++;
  }
  cout<<count<<endl;
  return 0;
}
