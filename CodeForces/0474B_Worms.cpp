#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

inline void findWorm(const vector<int>& worms,const vector<int>& labels){
  for(const int& l : labels){
    int lo = 0;
    int hi = worms.size() - 1;
    while(lo < hi){
      if(worms[lo] >= l){
	cout<<lo+1<<endl;
	break;
      }
      if(worms[hi-1] < l){
	cout<<hi+1<<endl;
	break;
      }
      int mid = lo + (hi-lo)/2;
      if(worms[mid - 1] < l && l <= worms[mid]){
	cout<<mid+1<<endl;
	break;
      }
      if(worms[mid] < l){
	lo = mid + 1;
      }else{
	hi = mid - 1;
      }
    }
  }
}

int main(){
  std::ios_base::sync_with_stdio (false);
  int piles;
  cin>>piles;
  //vector<int> worms(piles,0);
  vector<int> sum (piles,0);
  int s = 0;
  for(int i = 0; i < piles; ++i){
    int n;
    cin>>n;
    sum[i]=s+n;
    s=sum[i];
  }
  int wNums;
  cin>>wNums;
  vector<int> wormLabels(wNums,0);
  for(int i = 0; i < wNums; ++i){
    int n;
    cin>>n;
    wormLabels[i] = n;
  }
  //partial_sum(worms.begin(),worms.end(),sum.begin());
  findWorm(sum,wormLabels);
}
