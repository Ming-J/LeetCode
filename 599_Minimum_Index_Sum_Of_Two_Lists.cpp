/*
Suppose Andy and Doris want to choose a restaurant for dinner, and
they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least
list index sum. If there is a choice tie between answers, output all
of them with no order requirement. You could assume there always
exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".

Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1,
				vector<string>& list2) {
    vector<string> ans;
    unordered_map<string,int> favorite;
    for(size_t i=0;i<list1.size();i++){
      favorite[list1[i]]=i;    //store everything into map
    }
    unordered_map<string,int>::iterator it;
    int min;
    for(size_t i=0;i<list2.size();i++){
      it=favorite.find(list2[i]);
      if(it!=favorite.end()){
	int index=it->second+i;
	if(ans.empty()){  //if ans is empty we will push in the restaurant
	  min=index;
	  ans.push_back(it->first);
	}else{
	  if(min>index){  //check if the new index are small 
	    ans.assign(1,it->first);
	  }
	  if(min==index){
	    ans.push_back(it->first);
	  }
	}
      }
    }
    return ans;
  }
};
