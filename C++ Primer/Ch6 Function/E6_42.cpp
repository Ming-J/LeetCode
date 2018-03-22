#include <iostream>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s"){
  return (ctr>1) ? word + ending : word;
}

int main(){
  cout<<make_plural(1,"Success")<<' '<<make_plural(3,"Success","es")<<endl;
  cout<<make_plural(1,"Failure")<<' '<<make_plural(3,"Failure")<<endl;
}
