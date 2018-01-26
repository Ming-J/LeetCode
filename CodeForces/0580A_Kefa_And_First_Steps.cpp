#include <iostream>
#include <vector>
using namespace std;


int main(){
  int n;
  cin >> n;
  int count = 0;
  int maxcount = 0;
  int pre = -1;
  vector<int> arr;
  for( int i = 0 ; i < n ; i++){
    int temp;
    cin>>temp;
    arr.push_back(temp);
  }
  for(int i = 0; i < arr.size(); i++){
    if(arr[i] >= pre){
      count++;
    }else{
      maxcount = max( maxcount, count);
      count = 1;
    }
    pre = arr[i];
  }
  maxcount = max( maxcount,count);
  cout<<maxcount<<endl;
}
