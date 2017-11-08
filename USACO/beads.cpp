/*
ID:mingjou1
PROB: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;

int cutnecklace(int pos,string sequence,int n){
  char c1=0;
  char c2=0;
  int count=0;
  while(pos<sequence.size()){
    if(c1==0){
      if(sequence[pos]!='w'){
	c1=sequence[pos];
      }
    }else if(sequence[pos]!=c1&&c2==0){
      if(sequence[pos]!='w'){
	c2=sequence[pos];
      }
    }else if(c2!=0){
      if(sequence[pos]!='w'&&sequence[pos]!=c2){
	if(count>=n){
	  return n;
	}else{
	  return count;
	}
      }
    }
    count++;
    pos++;
  }
  return n;
}
int main(){
  ifstream fi;
  fi.open("beads.in");
  int n;
  fi>>n;
  string bread;
  fi>>bread;
  int maximum=0;
  for(int i=0;i<bread.size();i++){
    maximum=max(maximum,cutnecklace(i,bread+bread,n));
  }
  fi.close();
  fstream fout;
  fout.open("beads.out",fstream::out);
  fout<<maximum<<endl;
  fout.close();
  return 0;
}
