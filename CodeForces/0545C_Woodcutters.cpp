#include <iostream>
#include <vector>
using namespace std;

int woodHelp(vector< pair<int,int> > &woods, int i, int highest){
  if(i < woods.size()){
    if(highest >= woods[i].first){
      return 0;
    }
    if(highest >= woods[i].first - wood[i].second){
      return woodHelp(wood, i+1, woods[i].first);
    }


    
    int fall = max( woodHelp(woods,i+1, woods[i].first),
		    woodHelp(woods,i+1, highest + woods[i].second));
    fall = max( fall,
		woodHelp(woods,i+1, woods[i].first));
    return fall;
  }
}

int woodcut(vector< pair<int,int> > woods){
  return woodHelp(woods,0,0);
} 

int main(){
  
}
