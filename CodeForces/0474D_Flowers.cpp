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
int dp[1000000];
int sumdp[1000000] = {0};
int preMax = 0;
int mod = 1e9 + 7;
int calDp(int k, int first, int last){
  while(last>=preMax){
    if(preMax < k){
      dp[preMax] = 1;
    }else if(preMax == k){
      dp[preMax] = 2;
    }else{
      dp[preMax] = (dp[preMax-1] + dp[preMax - k])%mod;
    }
    sumdp[preMax] = (sumdp[preMax-1] + dp[preMax])%mod;
    ++preMax;
  }
  //int sum = 0;
  //for(int i = first; i <= last; ++i){
  //  sum =  (sum + dp[i]) % mod;
  //}
  return (sumdp[last] - sumdp[first-1]+mod) % mod;
}

int rec(int k, int n){
  //cout<<n<<endl;
  if(n<k){
    return 1;
  }else if(k==n){
    return 2;
  }else{
    int sum = 0;
    sum += (rec(k,n-1) + rec(k,n-k));
    return sum;
  }
}
int first,last;
int main(){
  int test;
  int k;
  cin>>test>>k;
  for(int i = 0; i < test; ++i){
    cin>>first>>last;
    cout<<calDp(k,first,last)<<endl;
  }
}
