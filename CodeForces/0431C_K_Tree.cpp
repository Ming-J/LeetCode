#include <iostream>
#include <vector>
using namespace std;
long m = 1e9+7;

void calKtree(int &count,int path, int k, int atLeast, bool add){
  if(path==0){
    if(add)count++;
    return;
  }
  for(int i =1; i <= k&& path-i>=0;++i){
    if(i>=atLeast){
      add = true;
    }
    calKtree(count,path-i,k,atLeast,add);
  }
} 

int kTreedp(int path, int kTree, int atLeast){
  long dp[path+1][2];
  dp[0][0] = 1;
  dp[0][1] = 0;
  for( int i = 1; i < path+1; ++i){
    dp[i][0] = dp[i][1] = 0;
    for( int j = 1; j <= kTree; ++j){
      if(i - j >= 0){
	if( j < atLeast){
	  dp[i][0] = ((dp[i][0] % m) + (dp[i-j][0] % m))%m;
	  dp[i][1] = ((dp[i][1] % m) + (dp[i-j][1] % m))%m;
	}else{			
	  dp[i][1] = ((dp[i][1] % m) + (dp[i-j][0] % m))%m;
	  dp[i][1] = ((dp[i][1] % m) + (dp[i-j][1] % m))%m;
	}
      }
    }
  }
  return dp[path][1];
}

int main(){
  int path=50, kTree=6, atLeast=3;
  cin>>path>>kTree>>atLeast;
  //int count = 0;
  //calKtree(count,path,kTree,atLeast,false);
  //cout<<count<<endl;
  cout<<kTreedp(path,kTree,atLeast)<<endl;
}
