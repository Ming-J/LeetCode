#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class War{
public:
  War(vector<int> one, vector<int> two){
    for(size_t i  = 0; i < one.size(); ++i){
      p1.push(one[i]);
    }
    for(size_t i = 0; i < two.size(); ++i){
      p2.push(two[i]);
    }
  }
  
  int turn(){
    int fight = 0;
    unordered_set<string> s1,s2;
    while(!p1.empty() && !p2.empty()){
      string pattern1 = print(p1), pattern2 = print(p2);
      if(s1.find(pattern1) != s1.end() && s2.find(pattern2) != s2.end())
	return -1;
      s1.insert(pattern1);
      s2.insert(pattern2);
      if(p1.front()>p2.front()){
	p1.push(p2.front());
	p1.push(p1.front());
      }else{
	p2.push(p1.front());
	p2.push(p2.front());
      }
      p2.pop();
      p1.pop();
      fight++;
    }
    return fight;
  }
  int winner(){ return (!p1.empty())?1:2;}
  string print(queue<int> t){
    string val;
    while(!t.empty()){
      val += to_string(t.front());
      t.pop();
    }
    return val;
  }
  
private:
  queue<int> p1;
  queue<int> p2;
  vector< pair<int,int> > oddEven; 
};

int main(){
  int t;
  cin>>t;
  cin>>t;
  vector<int> one(t);
  for(auto& i : one) cin>>i;
  cin>>t;
  vector<int> two(t);
  for(auto& i : two) cin>>i;
  //vector<int> one = {1,3,4,2};
  //vector<int> two = {5};
  War temp(one,two);
  int res = temp.turn();
  if(res == -1)
    cout<<res<<endl;
  else
    cout<<res<<' '<<temp.winner()<<endl;
}
