#include <vector>
#include <iostream>
using namespace std;
struct sweet{
  vector<pair<int,bool> > sv;
  sweet(int n){
    for(int i=0;i<n;i++){
      sv.push_back(make_pair(i,false));
    }
  }
  int givesweet(int lo,int hi){
    int sum=0;
    for(int i=lo;i<=hi;i++){
      sum+=sv[i].first;
      sv[i].second=true;
    }
    while(lo>=0){
      if(sv[lo].second!=true){
	sum+=sv[lo].first;
	sv[lo].second=true;
	lo=-1;
      }
      lo--;
    }
    while(hi++<sv.size()){
      if(sv[hi].second!=true){
	sum+=sv[hi].first;
	sv[hi].second=true;
	hi=sv.size();
      }
    }
    return sum;
  }
};


int main() {
    int n;
    int s;
    cin >> n >> s;
    for(int a0 = 0; a0 < s; a0++){
        int l;
        int r;
        cin >> l >> r;
        // Write Your Code Here
    }
    return 0;
}
