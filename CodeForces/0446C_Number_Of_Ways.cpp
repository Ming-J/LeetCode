#include <iostream>
#include <vector>
using namespace std;

long long splitTo3(vector<long long> arr){
  //Calculating the sum of the arr, check if sum % 3 ==0
  long long int cSum = 0;
  for( auto s : arr){
    cSum += s;
  }
  if(cSum % 3 != 0){
    return 0;
  }
  //count the number of arr[i]...arr[n] == sum/3
  vector<int> cnt(arr.size(),1);
  //the sum of the count of number
  vector<int> sumCnt(arr.size(),1);
  long long int partialSum = 0;
  int cntSum = 0;
  for(int i = arr.size() - 1; i >= 0; i--){
    partialSum += arr[i];
    if(partialSum == cSum/3){
      cnt[i] = 1;
      //partialSum = 0;
    }else{
      cnt[i] = 0;
    }
    cntSum += cnt[i];
    sumCnt[i] = cntSum;
  }
  partialSum = 0;
  long long count = 0;
  //figure out where the first chunk are, and do sum[i+2] due to 3 chunk
  for(int i = 0; i < arr.size()-2; i++){
    partialSum += arr[i];
    if( partialSum == cSum/3 ){
      count += sumCnt[i+2];
    }
  }
  return count;
}

int main(){
  long long n, temp;
  cin>>n;
  vector<long long> inputs(n,0);
  for(int i = 0; i < inputs.size(); i++){
    cin>>temp;
    inputs[i] = temp;
  }
  cout<<splitTo3(inputs)<<endl;
}
