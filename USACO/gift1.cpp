/*
ID:mingjou1
PROG: gift1
LANG: C++11
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

class gift{
private:
  vector<string> name;
  vector<int> wallet;
public:
  void addName(string people){
    name.push_back(people);
    wallet.push_back(0);
  }
  void modifyWallet(string person, int amount){
    for(int i=0;i<name.size();i++){
      if(name[i]==person){
	wallet[i]+=amount;
      }
    }
  }
  void print(string filename){
    ofstream myfile;
    myfile.open(filename.c_str());
    for(int i=0;i<name.size();i++){
      string line=name[i]+" "+to_string(wallet[i]);  
      myfile<<line.c_str()<<endl;
    }
    myfile.close();
  }
};

int main(){
  ifstream myfile("gift1.in");
  string line;
  getline(myfile,line);
  istringstream iss(line);
  int numberOfpeople;
  iss>>numberOfpeople;
  gift NP;
  for(int i=0;i<numberOfpeople;i++){
    getline(myfile,line);
    NP.addName(line);
  }
  int split;
  int peopleToSplite;
  while(getline(myfile,line)){
    split=0;
    peopleToSplite=0;
    string money;
    getline(myfile,money);
    istringstream issk(money);
    issk>>split;
    issk>>peopleToSplite;
    if(peopleToSplite>0){
      NP.modifyWallet(line,split*-1+split%peopleToSplite);
    }
    for(int i=0;i<peopleToSplite;i++){
      getline(myfile,money);
      NP.modifyWallet(money,split/peopleToSplite);
    }
  }
  myfile.close();
  NP.print("gift1.out");
  return 0;
}
