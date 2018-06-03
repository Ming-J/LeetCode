#include <iostream>
#include <vector>
using namespace std;

//6*7
vector<string> getGrid(string input){
  //decoding the string first
  string decode="";
  for(size_t i = 0; i < input.size(); ++i){
    if(isdigit(input[i])){
      if(!isdigit(input[i+1])){
	decode += string(input[i]-'0',input[i+1]);
	cout<<input[i]<<endl;
	++i;
      }else{
	string num = input.substr(i,2);
	decode += string(stoi(num),input[i+2]);
	i+=2;
      }
    }else{
      decode += input[i];
    }
  }
  //if string is not valid then return blank board
  //else return the grid
  vector<string> grid;
  for(int i = 0; i < decode.size(); ++i){
    if(i%7==0) cout<<endl;
    cout<<decode[i];
  }
  return grid;
}


int main(){
  string input = "9_r4_brbrbr_3b2rb_b2r2br_r2b3rb";
  vector<string> grid = getGrid(input);
}
