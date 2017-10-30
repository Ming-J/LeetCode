/*
ID:mingjou1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
using namespace std;
int IsLeapYear(int);
int main(){
  //week starts from SAT
  vector<int> weeks(7,0);
  vector<int> daysInMonth={31,28,31,30,31,30,31,31,30,31,30,31};
  //first sat on a SAT
  FILE *file;
  file=fopen("friday.in","r");
  int n;
  fscanf(file,"%d",&n);
  weeks[0]++;
  int days=0;
  int year=1900;
  while(year<1900+n){
    for(int i=0;i<daysInMonth.size();i++){
      if(i+1!=2){
	days+=daysInMonth[i];
      }else{
	if(IsLeapYear(year)){
	  days+=daysInMonth[i]+1;
	}else{
	  days+=daysInMonth[i];
	}
      }
      weeks[days%7]++;
    }
    year++;
  }
  weeks[days%7]--;
  ofstream myfile;
  myfile.open("friday.out");
  myfile<<weeks[0]<<" "<<weeks[1]<<" "<<weeks[2]<<" "<<weeks[3]<<" "
	<<weeks[4]<<" "<<weeks[5]<<" "<<weeks[6]<<'\n';
  myfile.close();
  return 0;
}
int IsLeapYear(int y){
  if((y%100==0&&y!=2000)||(y%4!=0)){
    return 0;
  }else{
    return 1;
  }
}
  
