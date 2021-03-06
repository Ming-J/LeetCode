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

class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    if(M.size() == 1) return 1;
    vector<bool> inCircle(M.size(), false);
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
