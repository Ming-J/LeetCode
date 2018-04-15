#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int m,n;
  cin>>m>>n;
  for(size_t i = 0; i < m; ++i){
    for(size_t j = 0; j < n; ++j){
      char c;
      cin>>c;
      switch(c){
      case 'C':
      case 'M':
      case 'Y':
	cout<<"#Color"<<endl;
	return 0;
	break;
	}
    }
  }
  cout<<"#Black&White"<<endl;
}
