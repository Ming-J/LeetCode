#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isSpruce(vector< pair<int,int> > tree){
  unordered_set<int> leaf;
  for(int i = 1; i <= tree.size() + 1; ++i)
    leaf.insert(i);
  unordered_set<int> nonLeaf;
  vector< vector<int> > children(tree.size() + 1);
  for(auto pa : tree ){
    children[pa.second].push_back(pa.first);
    if(nonLeaf.find(pa.second) == nonLeaf.end()){
      nonLeaf.insert(pa.second);
      leaf.erase(pa.second);
    }
  }
  for(auto it = nonLeaf.begin(); it != nonLeaf.end(); ++it){
    int isLeaf = 0;
    for(int itChildren : children[*it] ){
      if(leaf.find(itChildren) != leaf.end() ) ++isLeaf;
    }
    if(isLeaf < 3) return false;
  } 		 
  return true;
}


int main(){
  vector< pair<int,int> > input;
  int t;
  cin>>t;
  for(int i = 2; i <= t; ++i){
    int p;
    cin>>p;
    input.push_back({i,p});
  }
  if(isSpruce(input)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
