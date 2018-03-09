#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//recursive solution
int woodHelp(vector< pair<int,int> > &woods, int i, int highest){
  if(i == 0){
    //first tree always fall left
    return woodHelp(woods,i+1,woods[i].first) + 1;
  }else if( i == woods.size() - 1){
    //last tree can always fall right
    return 1;
  }else{
    int c1 = -1, c2 = -1, c3 = -1;
    //if the tree still stands
    c1 = woodHelp(woods,i+1,woods[i].first);

    //if the tree fall left, have to check if the previous highest is
    //in the way
    if(highest < woods[i].first - woods[i].second){
      c2 = woodHelp(woods,i+1,woods[i].first)+1;
    }

    //if the tree fall right, have to check if the next tree is in the
    //way
    if(woods[i].first + woods[i].second < woods[i+1].first){
      c3 = woodHelp(woods,i+1,woods[i].first+woods[i].second)+1;
    }
    return max(max(c1,c2),c3);
  }
}

int wooddp(vector< pair<int,int> > &woods){
  // 0 fall left 1 fall right 2 stand
  woods.push_back({INT_MAX,1});
  int dp[woods.size()][3] = {0};
  dp[0][0] = 1;
  if(woods[0].first + woods[0].second < woods[1].first) dp[0][1] = 1;
  for( size_t i = 1; i < woods.size()-1; ++i){
    int left = dp[i-1][0], right = dp[i-1][1], stand = dp[i-1][2];
    int previous = max( max(left,right), stand);
    //if current stand
    dp[i][2] = previous;
    //falls left
    //check previous fall left
    if( woods[i].first - woods[i].second > woods[i-1].first){
      dp[i][0] = max(dp[i][0],previous+1);
    }
    //check previous fall right
    if( woods[i].first - woods[i].second > woods[i-1].first + woods[i].second){
      dp[i][0] = max(dp[i][0],dp[i-1][1]+1); 
    }
    //check right
    if(woods[i].first + woods[i].second < woods[i+1].first){
      dp[i][1] = previous + 1;
    }
  }
  return dp[woods.size()-2][1];
}

int woodcut(vector< pair<int,int> > woods){
  return wooddp(woods);
} 

int main(){
  int n, tree, length;
  vector<pair<int,int> >woods;
  cin>>n;
  for(int i = 0; i < n; ++i){
    cin>>tree>>length;
    woods.push_back({tree,length});
  }
  cout<<woodcut(woods)<<endl;
}
