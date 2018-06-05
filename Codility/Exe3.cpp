#include <iostream>
using namespace std;

void to_lower(char *s){
  while(*s!='\0'){
    if(*s>='A'&&*s<='Z'){
      *s = (*s-'A')+'a';
    }
    ++s;
  }
}

int main(){
  char input[] = "Hello OMG I hate char ARRAY";
  to_lower(input);
  cout<<input<<endl;
}
