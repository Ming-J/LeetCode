#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  bool seats = false;
  vector<string> bus;
  cin>>n;
  for(int i = 0; i < n; ++i){
    string row;
    cin>>row;
    if(!seats&&row[0]=='O'&&row[1]=='O'){
      row[0] = row[1] = '+';
      seats = true;
    }
    if(!seats&&row[3]=='O'&&row[4]=='O'){
      row[3] = row[4] = '+';
      seats = true;
    }
    bus.push_back(row);
  }
  if(seats){
    cout<<"YES"<<endl;
    for(auto s : bus){
      cout<<s<<endl;
    }
  }else{
    cout<<"NO"<<endl;
  }
}
