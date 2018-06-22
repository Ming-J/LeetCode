#include <iostream>
using namespace std;

int main(){
  string n;
  cin>>n;
  for(size_t i = 0; i < n.size(); ++i){
    char& c = n[i];
    if(i!=0||c!='9'){
      if(c-'0'> (9 - (c-'0'))) c = 9 - (c-'0') + '0';
    }
  }
  cout<<n<<endl;
}
