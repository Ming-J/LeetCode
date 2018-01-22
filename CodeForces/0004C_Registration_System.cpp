#include <iostream>
#include <unordered_map>
using namespace std;

void insertName(unordered_map<string,int>&, string);

int main(){
  int n;
  cin>>n;

  unordered_map<string,int> database;
    
  for( int i = 0; i < n; i++){
    string inputname;
    cin>>inputname;
    insertName(database,inputname);
  }
  return 0;
}

void insertName(unordered_map<string,int>& database, string name){
  unordered_map<string,int>::iterator it;
  it = database.find(name);
  if(it != database.end()){
    int repeated = database[name];
    string newUsername = name+to_string(repeated);
    database.insert( make_pair(newUsername,(int)1) );
    cout<<newUsername<<endl;
  }else{
    cout<<"OK"<<endl;
  }
  database[name]++;
}
