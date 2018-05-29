#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;
//It's a bi-directional tree
//When there are no nodes to visit, it's the the leaf.
void getInput(int&,int&,vector<bool>&, unordered_map<int,vector<int> >&);
void findRestaurant(int from,int catTolerance, vector<bool>& containCat,
		    vector<bool>& visited,
		    unordered_map<int, vector<int> >& tree, int& count, int tolerance){
  //We are in the leaves, increase the count;
  if(visited[from-1]) return;
  visited[from-1]=true;
  bool leaveflag = true;
  for(size_t i = 0; i < tree[from].size(); ++i){
    int to = tree[from][i];
    if(!containCat[from-1]&&!visited[to-1]){
      leaveflag = false;
      findRestaurant(to,catTolerance,containCat,visited,tree,count,catTolerance);
    }else{
      if(tolerance - 1 >= 0&&!visited[to-1]){
	leaveflag =false;
	findRestaurant(to,catTolerance,containCat,visited,tree,count,tolerance-1);
      }
    }
  }
  if(leaveflag){
    if(tolerance!=0||!containCat[from-1]) ++count;
    return;
  }

}

int main(){
  int vertices,catTolerance;
  vector<bool> containCat;
  unordered_map<int,vector<int> > tree;
  getInput(vertices,catTolerance,containCat,tree);
  tree.insert({1,{}});
  int cnt=0;
  vector<bool> visited(vertices,false);
  findRestaurant(1,catTolerance,containCat,visited,tree,cnt,catTolerance);
  cout<<cnt<<endl;
  return 0;
}
// c++ bool value true=1, false = 0
void getInput(int& vertices,int& catTolerance, vector<bool>& containCat,
	      unordered_map<int, vector<int> >& tree){
  cin>>vertices>>catTolerance;
  containCat.resize(vertices,false);
  for(int i = 0; i < vertices; ++i){
    int t;
    cin>>t;
    containCat[i]=t;
  }
  for(int i = 0; i < vertices - 1; ++i){
    int from,to;
    cin>>from>>to;
    if(tree.find(from)==tree.end()){
      tree.insert({from,{to}});
    }else{
      tree[from].push_back(to);
    }
    if(tree.find(to) == tree.end()){
      tree.insert({to,{from}});
    }else{
      tree[to].push_back(from);
    }
  }
}
