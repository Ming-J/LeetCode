#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void inc(vector<int> &arr){
  transform(arr.begin(),arr.end(),arr.begin(),[](int val){return val+1;});
}
void dec(vector<int> &arr){
  transform(arr.begin(),arr.end(),arr.begin(),[](int &val){return val-1;});
}

int calOrigin(string s){
  int p = 0;
  for( char c: s){
    if(c == '+'){
      p++;
    }else{
      p--;
    }
  }
  return p;
}

double calMod(string s, int target){
  vector<int> pos = {0};
  for(char c: s){
    if(c == '+'){
      inc(pos);
    }
    if(c == '-'){
      dec(pos);
    }
    if( c == '?'){
      vector<int> newPos1 = pos;
      vector<int> newPos2 = pos;
      inc(newPos1);
      dec(newPos2);
      newPos1.insert(newPos1.end(),newPos2.begin(),newPos2.end());
      pos = newPos1;
    }
  }
  int i=0;
  for( int val : pos){
    if( val == target) i++;
  }
  return i*1.0/pos.size();
}

int main(){
  string orig, modif;
  cin>>orig>>modif;
  int finalPoint = calOrigin(orig);
  cout<<fixed<<setprecision(9)<<calMod(modif,finalPoint)<<endl;
  return 0;
}
