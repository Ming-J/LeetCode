#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Less{
public:
  void cal(vector<int> A, vector<int> B){
    sort(A.begin(), A.end());
    int A_index = 0;
    int count = 0;
    for(auto B_i : B){
      auto it = upper_bound(A.begin(),A.end(),B_i);
      cout<<it-A.begin()<<' ';
    }
  }
};


int main(){
  int n,m;
  cin>>n>>m;
  vector<int> input1(n);
  vector<int> input2(m);
  for(auto& i : input1) cin>>i;
  for(auto& i : input2) cin>>i;
  Less temp;
  temp.cal(input1, input2);
}
