#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct house{
  int index;
  int stash;
  house(int s, int i){
    stash=s;
    index=i;
  }
  bool operator<(const house& rhs)const {
    return stash<rhs.stash;
  }
};


class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size()==1){return nums[0];};
    int robbery=0;
    vector<house> arr;
    for(int i=0;i<nums.size();i++){
      arr.push_back(house(nums[i],i));
    }
    sort(arr.begin(),arr.end());
    vector<bool> visited(false,nums.size());
    for(int j=0;j<arr.size();j++){
      int i=arr[j].index;
      if(i==0){
	if(!visited[i+1]){
	  robbery+=arr[j].stash;
	  visited[i]=true;
	}
      }else if(i==nums.size()-1){
	if(!visited[i-1]){
	  robbery+=arr[j].stash;
	  visited[i]=true;
	}
      }else{
	if(!visited[i+1]&&!visited[i-1]){
	  robbery+=arr[j].stash;
	  visited[i]=true;
	}
      }     
    }      
    return robbery;
  }
};


int main(){
  cout<<"Hello World"<<endl;
}
