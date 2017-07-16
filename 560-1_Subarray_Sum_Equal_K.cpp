#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution{
public:
  int subarraySum(vector<int>& nums, int k){
    deque<int> subarray;
    int dequesum=0;
    int total=0;
     
    return total;
  }
};

int main(){
  cout<<"Hello World"<<endl;
  int numarray[]={28,54,7,-70,22,65,-6};
  vector<int> input(numarray,numarray+sizeof(numarray)/sizeof(numarray[0]));
  Solution test;
  cout<<test.subarraySum(input,100)<<endl;
}
