#include <iostream>
#include <vector>
using namespace std;

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
  int dp[path+1][2] = {0};
  dp[0][0] = 0;
  dp[0][1] = 0;
  for( int i = 1; i < path+1; ++i){
    for( int j = 1; j <= kTree; ++j){
      if(i - j >= 0){
	if( j < atLeast){
	  dp[i][0] += dp[i-j][0] + 1;
	  dp[i][1] += dp[i-j][1];
	}else{
	  dp[i][1] += (dp[i-j][1]+(dp[i-j][0] + 1));
	}
      }
    }
  }
  return dp[path][1];
}

int main(){
  int path=28, kTree=6, atLeast=3;
  //cin>>path>>kTree>>atLeast;
  int count = 0;
  calKtree(count,path,kTree,atLeast,false);
  cout<<count<<endl;
  cout<<kTreedp(path,kTree,atLeast)<<endl;
}
