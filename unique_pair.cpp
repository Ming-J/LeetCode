#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int uniquePairs(vector<int> &nums, int k){
    if(nums.size()==0){
      return 0;
    }
    unordered_map<int,int> hash;
    unordered_map<int,int>::iterator it;
    for(int i=0;i<nums.size();i++){
      it=hash.find(nums[i]);
      if(it==hash.end()){
	hash[nums[i]]=1;
      }else{
	hash[nums[i]]++;
      }
    }
    int count=0;
    for(it=hash.begin();it!=hash.end();it++){
      unordered_map<int,int>::iterator comp;
      int dif=k-it->first;
      comp=hash.find(dif);
      if(comp!=hash.end()){
	count=count+min(it->second,comp->second)*2;
	hash[dif]=hash[dif]-min(it->second,comp->second);
	it->second=it->second-min(it->second,comp->second);
      }
    }
    return count;
  }
};


int main(){
  int arr[5]={2,4,2,4,6};
  vector<int> input(arr,arr+sizeof arr/sizeof arr[0]);
  Solution test;
  cout<<test.uniquePairs(input,8)<<endl;
}
