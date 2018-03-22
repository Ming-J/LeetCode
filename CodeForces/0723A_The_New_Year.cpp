#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int findCenter(int a , int b, int c){
  int arr[3] = {a,b,c};
  sort(begin(arr),end(arr));
  int dif = arr[2] - arr[0];
  return dif;
}

int main(){
  int a, b , c;
  cin>>a>>b>>c;
  cout<<findCenter(a,b,c)<<endl;
}
