#include <iostream>
#include <unordered_map>
using namespace std;
/*
  n student, form into k per team.  The rating are distinct.

*/

class Team{
public:
  Team(int s):size(s){}

  void add(int r, int i){
    rating.insert({r,i});
  }

  void validate(){
    string res = (rating.size()>=size)?"YES":"NO";
    int i = 0;
    cout<<res<<endl;
    if(res=="NO") return;
    for(auto it = rating.begin(); it != rating.end()&& i < size; ++it,++i){
      cout<<it->second<<' ';
    }
  }
  
private:
    unordered_map<int,int> rating;
  int size;
};

int main(){
  int n, k;
  cin>>n>>k;
  Team codehouse(k); 
  for(int i = 1;i <= n; ++i){
    int t;
    cin>>t;
    codehouse.add(t,i);
  }
  codehouse.validate();
  return 0;
}
