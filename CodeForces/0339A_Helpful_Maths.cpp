#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string fmu = "3+2+1";
  char c_arr[fmu.size()+1];
  //c_arr = strdup( fmu.c_str() );
  strcpy(c_arr,fmu.c_str());
  for( int i =0 ; i< fmu.size()+1; i++){
    cout<<c_arr[i];
  }
  //char *token = strtok(const_cast<char *>(fmu.c_str()),"+");
  char *token = strtok(&fmu[0],"+");
  int nArr[3]={0};
  while(token != NULL){
    cout<<token<<endl;
    nArr[token-'0']++;
    token = strtok(NULL, "+");
    }
  cout<<fmu<<endl;
}
