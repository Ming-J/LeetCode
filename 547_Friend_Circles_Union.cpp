#include <iostream>
#include <vector>
using namespace std;
/*
 N students;
 N*N matrix M , if M[i][j] = 1 then i and J are direct friends
 output: Number of friends circiles
 Having a array or vector to keep track students already in friend circle
 going through each student and dfs to group together 
 DFS
 Time Complexity: O(N^2)
*/

class Union{
public:
  Union(int n){
    unionSet.assign(n);
    for(int i = 0; i < unionSet.size(); ++i) unionSet[i] = i;
  }
  int root(int p){
    while(p != unionSet[p]){
      unionSet[p] = unionSet[unionSet[p]];
      p = unionSet[p];
    }
    return unionSet[p];
  }
  bool find(int p, int q){
    return root(p) == root(q);
  }
  void unite(int p , int q){
    int i = root(p);
    int j = root(q);
    unionSet[i] = j;
  }  
private:
  vector<int> unionSet;
}

class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    if(M.size() == 1) return 1;
    Union u(M.size());
    int circle = 0;
    for(size_t i = 0; i < M.size(); ++i){
      
      if(!inCircle[i]){
	++circle;
	inCircle[i] = true;
	checkFriend(M,inCircle,i);
      }
    }
    return circle;
  }

  void checkFriend(const vector<vector<int> >& M, vector<bool>& inCircle,
		   int student){
    for(size_t i = 0; i < M[student].size(); ++i){
      if(i!=student && !inCircle[i] && M[student][i] == 1){
	inCircle[i] = true;
	checkFriend(M,inCircle,i);
      }
    }
  }
};
