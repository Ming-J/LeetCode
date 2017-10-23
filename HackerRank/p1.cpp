#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
  string n;
  int intn;
  int number;
  cin>>n;
  intn=atoi(n.c_str());
  for(int i=1;i<=intn;i++){
    cin>>n;
    number=atoi(n.c_str());
    if(number%3==0&&number%5==0){
      if(i==intn){
	cout<<"GarnetGold";
      }
      else
	{
	  cout<<"GarnetGold"<<endl;
	}
    }
    else if(number%5==0)
      {
	if(i==intn)
	  {
	    cout<<"Gold";
	  }
	else
	  {
	    cout<<"Gold"<<endl;
	  }
      }
    else if(number%3==0)
      {
	if(i==intn)
	  {
	    cout<<"Garnet";
	  }
	else
	  {
	  cout<<"Garnet"<<endl;
	  }
      }else{
      if(i==intn)
	{
	  cout<<number;
	}
      else
	{
	cout<<number<<endl;
	}
    }
  }
  return 0;
}
