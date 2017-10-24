#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
private:
  int calfactorial(int k){
    int n=1;
    for(int i=0;i<k;i++){
      n*=i+1;
    }
    return n;
  }
public:
  string getPermutation(int n, int k){
    string s="";
    string ans="";
    for(int i=0;i<n;i++){
      s+=to_string(i+1);
    }
    cout<<s<<endl;
    while(ans.size()!=n){
      int factor=calfactorial(s.size()-1);
      cout<<"k:"<<k<<endl;
      int permu=calfactorial(s.size());
      //int mod=k%permu;
      int rem=k/factor;
      k%=factor;
      if(k==0){
	rem--;
	k=factor;
      }
      cout<<"f:"<<factor<<endl;
      cout<<"rem:"<<rem<<endl;
      char c=s[rem];
      s.erase(rem,1);
      ans+=c;
      cout<<ans<<endl;
    }
    //helper(s,0,k,ans);
    return ans;
  }
};

int main(){
  Solution test;
  cout<<test.getPermutation(3,4)<<"<-----"<<endl;;
  return 0;
}
