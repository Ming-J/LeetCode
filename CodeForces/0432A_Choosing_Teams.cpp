#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int student=5, participate=2;
  cin>>student>>participate;
  vector<int> times;
  int n;
  for(int i = 0 ; i < student ; i++){
    cin>>n;
    times.push_back(n);
  }
  sort(times.begin(),times.end());
  int team = 0;
  for( int i = 2; i < times.size() ; i += 3){
    if(times[i] + participate <= 5){
      team++;
    }
  }
  cout<<team<<endl;
}
