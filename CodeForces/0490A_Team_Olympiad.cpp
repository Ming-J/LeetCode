#include <iostream>
#include <vector>
//using std::cin, std::cout, std::endl, std::vector<T>;
using namespace std;
int main(){
  int n, skill;
  cin>>n;
  vector< vector<int> > students( 3, vector<int>() );
  for(size_t i = 0; i < n; ++i){
    cin >> skill;
    students[skill - 1].push_back(i+1); 
  }
  int teams = min(students[0].size(),
		  min(students[1].size(),students[2].size()));
  cout<<teams<<endl;
  for(size_t i = 0; i < teams; ++i){
    cout<<students[0][i]<<' '<<students[1][i]<<' '<<students[2][i]<<endl;
  } 
}
