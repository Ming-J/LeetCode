#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
  int n;
  cin>>n;
  unordered_map<string, int> mapping;
  mapping.insert({"Tetrahedron",4});
  mapping.insert({"Cube",6});
  mapping.insert({"Octahedron",8});
  mapping.insert({"Dodecahedron",12});
  mapping.insert({"Icosahedron",20});
  int sum = 0;
  for(int i = 0; i < n; ++i){
    string str;
    cin>>str;
    sum += mapping[str];
  }
  cout<<sum<<endl;
}
