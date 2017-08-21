#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
      string temp;
      for(int i=s.size()-1;i>=0;i--){
	temp.push_back(s[i]);
      }
      return temp;
    }
};

int main(){
  Solution test;;
  cout<<test.reverseString("Hello")<<endl;
}
