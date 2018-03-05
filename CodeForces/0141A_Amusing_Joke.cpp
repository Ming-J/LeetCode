#include <iostream>
#include <vector>
using namespace std;

void countChar(const string &s1, vector<int> &charArr){
  for(char c : s1){
    charArr[c-'A']++;
  }
}

int main(){
  string n1, n2, tot;
  cin>>n1>>n2>>tot;
  vector<int> individualChar(26,0);
  vector<int> totalChar(26,0);
  countChar(n1,individualChar);
  countChar(n2,individualChar);
  countChar(tot, totalChar);
  for(size_t i = 0; i < totalChar.size(); ++i){
    if(totalChar[i] != individualChar[i]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
