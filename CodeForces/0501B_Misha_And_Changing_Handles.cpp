#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Handle{
public:
  void insert(string oldName, string newName){
    if(names.find(oldName)==names.end()){
      names.insert({newName,oldName});
    }else{
      string original = names[oldName];
      names.erase(oldName);
      names.insert({newName,original});
    }
  }

  void print(){
    cout<<names.size()<<endl;
    for(auto it : names){
      cout<<it.second<<' '<<it.first<<endl;
    }
  }
  
 private:
    //current name          originalName,currentName
  unordered_map<string, string> names;
};


int main(){
  int t;
  cin>>t;
  Handle CF;
  for(int i = 0; i < t; ++i){
    string oldN, newN;
    cin>>oldN>>newN;
    CF.insert(oldN,newN);
  }
  CF.print();   
}
