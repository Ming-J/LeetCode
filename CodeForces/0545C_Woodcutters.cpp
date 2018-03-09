#include <iostream>
#include <vector>
using namespace std;

int woodHelp(vector< pair<int,int> > &woods, int i, int highest){
  if(i == 0){
    //fall left
    return woodHelp(woods,i+1,woods[i].first) + 1;
  }else if( i == woods.size() - 1){
    return 1;
  }else{
    int c1 = -1, c2 = -1, c3 = -1;
    c1 = woodHelp(woods,i+1,woods[i].first);

    if(highest < woods[i].first - woods[i].second){
      c2 = woodHelp(woods,i+1,woods[i].first)+1;
    }

    if(woods[i].first + woods[i].second < woods[i+1].first){
      c3 = woodHelp(woods,i+1,woods[i].first+woods[i].second)+1;
    }
    return max(max(c1,c2),c3);
  }
}

int woodcut(vector< pair<int,int> > woods){
  return woodHelp(woods,0,0);
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
