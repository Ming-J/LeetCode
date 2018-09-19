#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Password{
 public:
  Password(int c, vector<string> p, string co, int t):
    pwCount(c),pws(p),correct(co),trys(t) {}

  string calTry(){
    unordered_map<size_t,int> sizeCount;
    auto func = [&](string s){++sizeCount[s.size()];};
    for_each(pws.begin(),pws.end(),func);
    int occ = 0;
    int minSec = 0, maxSec = 0;
    for(size_t i = 1; i <= correct.size(); ++i){
      int curCount = static_cast<int>(i);
      if(sizeCount.find(curCount) != sizeCount.end()){
	if(i < correct.size()){
	  occ += sizeCount[curCount];
	}else{
	  int wait = occ/trys; 
	  minSec = occ+1 + wait*5;
	  occ += sizeCount[curCount];
	  wait = (occ-1)/trys;
	  maxSec = occ + wait*5;
	}
      } 
    }
    string result = to_string(minSec) + " " + to_string(maxSec); 
    return result;
  }

 private:
  int pwCount;
  vector<string> pws;
  string correct;
  int trys;
};


int main(){
  int n, t;
  cin>>n>>t;
  vector<string> input(n);
  for(string& s : input) cin>>s;
  string c;
  cin>>c;
  Password p(n,input,c,t);
  cout<<p.calTry()<<endl;
}
