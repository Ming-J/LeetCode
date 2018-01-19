#include <iostream>
using namespace std;

int main(){
  int n, t;
  cin>>n>>t;
  
  char arr[n];

  cin>>arr;

  for( int i = 0; i < t ; i++){
    for(  int j = 1 ; j < n ; j++ ){
      if( arr[j] == 'G' && arr[j-1] == 'B'){
	swap( arr[j], arr[j-1]);
	j++;
      }
    }
  }
  cout<<arr<<endl;
}
