#include <iostream>
#include <vector>
using namespace std;

//use back tracking
// ni is divisible by i
// i is divisible by the number at ith position
class Solution{
public:
  int countArrangement(int n){
    vector<int> res;
    vector<int> insert(n);
    for(int i = 1; i <= insert.size(); ++i){
      insert[i-1] = i;
    }
    int count = 0;
    backtrack(count,res,insert);
    return count;
  }

  void backtrack(int& count, vector<int>& arr, vector<int> insert){
    if(insert.size() == 0){
      //for(auto i : arr) cout<<i<<' ';
      //cout<<endl;
      ++count;
      return;
    }else{
      for(int i = 0; i < insert.size(); ++i){
	int t = insert[i];
	 if( t % (arr.size() + 1) == 0 || (arr.size() + 1) % t == 0){
	  insert.erase(insert.begin()+i);
	  arr.push_back(t);
	  backtrack(count,arr,insert);
	  arr.pop_back();
	  insert.insert(insert.begin()+i,t);
	}
      }
    }
  }
};

int main(){
  Solution test;
  cout<<test.countArrangement(15)<<endl;
}
