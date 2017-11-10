#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<int> lexicalOrder(int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
      ans.push_back(i+1);
    }
    sort(ans.begin(),ans.end(),
	 [](int l,int r){return to_string(l)<to_string(r);});
    return ans;
  }

  vector<int> lexOrder(int n){
    vector<int> ans;
    int num=1;
    while(ans.size()<n){
      ans.push_back(num);
      if(num*10<=n){
	num*=10;
      }else{
	if(num>=n){num/=10;}
	num++;
	while(num%10==0){num/=10;}
      }
    }
    return ans;
  }
};

int main(){
  Solution test;
  vector<int> ans=test.lexOrder(13);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
}
