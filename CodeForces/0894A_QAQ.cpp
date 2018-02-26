#include <iostream>
using namespace std;

int main(){
  string wrd;
  cin>>wrd;
  int qaq = 0;
  for(size_t i = 0; i < wrd.size(); ++i){
    if(wrd[i] == 'A'){
      int prefix=0, suffix = 0;
      for(size_t j = 0; j < i; ++j){
	if(wrd[j] == 'Q') prefix++;
      }
      for(size_t k = i+1; k < wrd.size(); ++k){
	if(wrd[k] == 'Q') suffix++;
      }
      qaq += prefix*suffix;
    }
  }
  cout<<qaq<<endl;
  return 0;
}
