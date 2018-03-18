#include <iostream>
using namespace std;
/*
  4w 4R
   2 3
   RR
   WW
   4
   RRRR
   WWWW
   RWWR
   RRWW
   WWRR
*/
int dp[10000+1];
int preMax = 0;
int calDp(int k, int first, int last){
  while(last>=preMax){
    if(){
      preMax;
  }
  return 0;
}

int rec(int k, int n){
  //cout<<n<<endl;
  if(n<k){
    return 1;
  }else if(k==n){
    return 2;
  }else{
    int sum = 0;
    //for(int i = 1; i <= k; ++i){
    sum+= (rec(k,n-1) + rec(k,n-k));
      //}
    return sum;
  }
}

int main(){
  int test = 3;
  int k = 5;
  cout<<rec(k,10)<<endl;

}
