#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
      if(tree.size() <=2 ) return tree.size(); 
      size_t begin = 0, end = 0;
      unordered_map<int,int> basket;
      int maxFruit = 0;
      while(begin<tree.size()&&end<tree.size()){
	while(begin<tree.size()&&
	      end<tree.size()&&
	      basket.size()<=2){
	  if(basket.size() == 2 &&
	     basket.find(tree[end]) == basket.end()) break;
	  ++basket[tree[end]];
	  ++end;
	}
	int fruit=0;
	for(auto p : basket) fruit += p.second;
	maxFruit = max(maxFruit,fruit);
	while(begin<tree.size()&&end<tree.size()&&
	      basket.size() == 2){
	  if(--basket[tree[begin]] == 0){
	    basket.erase(tree[begin]);
	  }
	  ++begin;
	}
      }
      return maxFruit;
    }
};

int main(){
  vector<int> tree = {3,3,3,1,2,1,1,2,3,3,4};
  Solution temp;
  cout<<temp.totalFruit(tree)<<endl;
}
