/*
ID: mingjou1
PROB: milk2
LANG: C++11
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct milk_t{
  int time;
  bool milking;
}milkStart, milkEnd;

int main(){
  milkStart.milking=true;
  milkEnd.milking=false;
  ifstream file;
  file.open("milk2.in");
  int famer;
  file>>famer;
  vector<milk_t> working;
  for(int i=0;i<famer;i++){
    int start;
    int end;
    file>>start>>end;
    milkStart.time=start;
    milkEnd.time=end;
    working.push_back(milkStart);
    working.push_back(milkEnd);
  }
  file.close();
  sort(working.begin(),working.end(),
       [](milk_t lhs,milk_t rhs){
	 if(lhs.time==rhs.time){
	   int a=lhs.milking?1:0;
	   int b=rhs.milking?1:0;
	   return a>b;
	 }else{
	   return lhs.time<rhs.time;}});
  stack<milk_t> deck;
  int maxContinue=0;
  int maxOff=0;
  int continuestart=0;
  int offtimestart=0;
  for(int i=0;i<working.size();i++){
    if(deck.empty()){
      continuestart=working[i].time;
      if(offtimestart!=0){
	maxOff=max(maxOff,continuestart-offtimestart);
      }
      deck.push(working[i]);
    }else if(working[i].milking){
      deck.push(working[i]);
    }else if(!working[i].milking){
      deck.pop();
      if(deck.empty()){
	offtimestart=working[i].time;
	maxContinue=max(maxContinue,offtimestart-continuestart);
      }
    }
    //cout<<working[i].time<<endl;
  }
  ofstream fout;
  fout.open("milk2.out");
  fout<<maxContinue<<" "<<maxOff<<endl;
  fout.close();
  return 0;
}
