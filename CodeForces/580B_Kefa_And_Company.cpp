#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  n friends, D MINIMUM DIFFERENCE 
  MXIMUM FIRENDSHIP
  mi -> amount of money friends own
  si -> friendship factor
*/

int main(){
  int friends, diff;
  cin>>friends>>diff;
  vector< pair< int, int > > companys;
  for(int i = 0; i < friends; ++i){
    int m, s;
    cin>>m>>s;
    companys.push_back(make_pair(m,s));
  }
  //sort them by second value
  sort(companys.begin(),companys.end());
  long long int maxFriendship = 0;
  int j = 1;
  long long int friendship = companys[0].second;
  for(int i = 0; i < companys.size(); ++i){
    while(j < companys.size() &&
	  abs(companys[i].first - companys[j].first) < diff){
      friendship += companys[j].second;
      ++j;
    }
    maxFriendship = max(maxFriendship,friendship);
    friendship -= companys[i].second;
  }
  cout<<maxFriendship<<endl;
}
