/*
ID: mingjou1
PROG: ride
LANG: C++
 */
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class UFO{
private:
  int co;
  int go;
public:
  UFO(string comet, string group){
    co=1;
    go=1;
    for(int i=0;i<comet.size();i++){
      int v=comet[i]-'@';
      co*=v;
    }
    for(int i=0;i<group.size();i++){
      int v=group[i]-'@';
      go*=v;
    }
    co%=47;
    go%=47;
  }
  string check(){
    if(go==co){
      return "GO\n";
    }else{
      return "STAY\n";
    }
  }
};

int main(){
  FILE * pfile;
  char one[256];
  string comet;
  char two[256];
  string group;
  pfile= fopen("ride.in","r");
  fscanf(pfile,"%s",one); 
  fscanf(pfile,"%s",two);
  fclose(pfile);
  comet=string(one);
  group=string(two);
  UFO take1(comet,group);
  pfile=fopen("ride.out","w");
  fprintf(pfile,"%s",take1.check().c_str());
  fclose(pfile);
  return 0;
}
