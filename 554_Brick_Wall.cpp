#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 Use unordered map to store where the crack is at. Figure out the
 position where it has the most cracks. Reutrn the number of rows
 minus the cracks, which is the number of brick needed to be passed
*/
class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    // using hash to store the cracks
    unordered_map<int, int> hash;
    int cracks = 0;
    for(int i = 0; i < wall.size(); i++){
      int length = 0 ;
      for(int j = 0; j < wall[i].size() - 1; j++){
	length += wall[i][j];
	hash[length]++;
	cracks = max(cracks,hash[length]);
      }
    }
    return wall.size() - crack;
  }
};
