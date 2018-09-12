/*
  
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  size_t n;
  cin>>n;
  vector<long long> arr(2*n);
  for(long long& i : arr){
    cin>>i;
  }
  sort(arr.begin(),arr.end());
  long long ans = (arr[n-1] - arr[0]) * (arr[2*n-1] - arr[n]);
  long long c = arr[2*n-1] - arr[0];
  for(size_t i = 1; i <= n; ++i){
    long long temp = c * (arr[i+n-1] - arr[i]);
    ans = min(ans, temp);
  }
  cout<<ans<<endl;
  return 0;
}
