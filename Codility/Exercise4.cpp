#include <iostream>
using namespace std;

void swap(std::string* s1, std::string* s2){
  cout<<s1<<'/'<<s2<<endl;
  std::string* temp = s1;
  s1 = s2;
  s2 = temp;
  cout<<s1<<'/'<<s2<<endl;
}

int main(){
  string s1 = "Before";
  string s2 = "After";
  string* p1 = &s1;
  string* p2 = &s2;
  cout<<p1<<*p1<<" "<<p2<<*p2<<endl;
  swap(&s1,&s2);
  cout<<p1<<*p1<<" "<<p2<<*p2<<endl;
  cout<<s1<<" "<<s2<<endl;
}
