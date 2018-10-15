#include <iostream>
using namespace std;

string reverseEq(string eq){
  string res = "";
  int j = 0;
  for(int i = 0; i < eq.size(); ++i){
    if(eq[i] == '+'||eq[i] == '*'||eq[i] == '/'||eq[i] == '-'){
      res.insert(res.begin(),eq.begin()+j,eq.begin()+i);
      j = i+1;
      res.insert(res.begin(),eq[i]);
    }
  }
  res.insert(res.begin(),eq.begin()+j,eq.end());
  return res;
}

int main(){
  string input = "a+b*c-d/e";
  cout<<"input: "<<input<<endl;
  cout<<"Output: "<<reverseEq(input)<<endl;
}
