#include <iostream>
#include <unordered_set>
using namespace std;

class Solution{
public:
  bool canConstruct(string ransomNote, string magazine){
    unordered_multiset<char> charBank;
    for(int i=0;i<magazine.size();i++){
      charBank.insert(magazine[i]);
    }
    unordered_multiset<char>::iterator it;
    for(int i=0;i<ransomNote.size();i++){
      it=charBank.find(ransomNote[i]);
      if(it!=charBank.end()){
	charBank.erase(it);
      }
      else{
	return false;
      }	
    }
    cout<<ransomNote<<" "<<endl;
    return true;
  }
};



int main(){
  Solution test;
  test.canConstruct("a","b");
  return 0;
}
