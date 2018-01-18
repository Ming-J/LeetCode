#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string fmu = "3+2+1+2+3";
  cin>>fmu;
  char c_arr[fmu.size()+1];
  //c_arr = strdup( fmu.c_str() );

  //making an array copy
  strcpy(c_arr,fmu.c_str());;


  //char *token = strtok(const_cast<char *>(fmu.c_str()),"+");
  //using strtok will modify the original string with "@"
  char *token = strtok(&fmu[0],"+");
  int nArr[3]={0};
  while(token != NULL){
    nArr[atoi(token)-1]++;
    token = strtok(NULL, "+");
  }
  string res;
  for(int i=0;i < 3;i++){
    for(int j=0;j<nArr[i];j++){
      if(res.empty()){
	res += to_string(i+1);
      }else{
	res += '+'+to_string(i+1);
      }
    }
  }
  cout<<res<<endl;
}
