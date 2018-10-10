#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  n
  c to another city
  0 1 2 2 2 2 3 4 4 7 9
*/

class Prisoner{
public:
  Prisoner(int c, int t, vector<int> s):contiguous{c},serverity{t}
				       ,crimes{s}{}
  int calculate(){
    vector<int> index;
    int i = 0;
    int c = 0;
    auto func = [&](int x){
		  if(x>serverity) index.push_back(i);
		  ++i;
		};
    for_each(crimes.begin(),crimes.end(),func);
    if(index.size() == 0){
      c = (crimes.size() - contiguous + 1);
      c = (c>0)?c:0;
    }
    for(int i = 0; i < index.size(); ++i){
      if(i == 0){
	int element = index[i];
	if((element - contiguous + 1) > 0 )c += element - contiguous + 1;
      }
      if( i == index.size() - 1){
	int element = crimes.size() - 1 - index[i];
	if((element - contiguous + 1) > 0 )c += element - contiguous + 1;
	break;
      }
      if(i+1 < crimes.size()){
	int element = index[i+1] - index[i] - 1;
	if((element - contiguous + 1) > 0 )c += element - contiguous + 1;
      }
    }
    return c;
  }
  
private:
  int contiguous;
  int serverity;
  vector<int> crimes;
};


int main(){
  int n, ser, c;
  cin>>n>>ser>>c;
  vector<int> crimes(n,0);
  for(int& t : crimes) cin>>t;
  Prisoner temp(c,ser,crimes);
  cout<<temp.calculate()<<endl;
}
