#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int calButton(int n, int m){
  queue<int> q;
  unordered_set<int> s;
  q.push(n);
  s.insert(n);
  int level = 0;
  while(!q.empty()){
    size_t size = q.size();
    ++level;
    for(size_t i = 0; i < size; ++i){
      int n1 = q.front() * 2;
      int n2 = q.front() - 1;
      if(n1 == m || n2 == m){
	return level;
      }
      q.pop();
      if(s.find(n1) == s.end()){
	s.insert(n1);
	if(m *2 > n1 && n1 >= 0 ) q.push(n1);
      }
      if(s.find(n2) == s.end()){
	s.insert(n2);
	if(n2 >= 0) q.push(n2);
      }
    }
  }
  return -1;
}

int main(){
  int n,m;
  cin>>n>>m;
  cout<<calButton(n,m)<<endl;
}
