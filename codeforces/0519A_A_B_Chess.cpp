#include <iostream>
#include <unordered_map>
using namespace std;

void calWeight(string row,
	       const unordered_map<char,int>& weight, int &black, int &white){
  for(auto c : row){
    if(weight.find(toupper(c)) != weight.end()){
      int val = weight.find(toupper(c))->second;
      if(isupper(c)){
	white += val;
      }else{
	black += val;
      }
    } 
  }
}

int main(){
  unordered_map<char,int> weightMap;
  weightMap.insert({'Q',9});
  weightMap.insert({'R',5});
  weightMap.insert({'B',3});
  weightMap.insert({'N',3});
  weightMap.insert({'P',1});
  int black = 0;
  int white = 0;
  for(int i = 0; i < 8; ++i){
    string r;
    cin>>r;
    calWeight(r,weightMap,black,white);
  }
  if(black == white){
    cout<<"Draw"<<endl;
  }else if(black > white){
    cout<<"Black"<<endl;
  }else{
    cout<<"White"<<endl;
  }
 };
