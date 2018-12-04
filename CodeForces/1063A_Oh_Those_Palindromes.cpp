#include <iostream>
#include <algorithm>
using namespace std;

class Pal{
public:
  string cal(string w){
    sort(w.begin(),w.end());
    return w;
  }
};

int main(){
  int n;
  cin>>n;
  string w;
  cin>>w;
  Pal temp;
  cout<<temp.cal(w)<<endl;
}
