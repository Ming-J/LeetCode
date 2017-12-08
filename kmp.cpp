#include <iostream>
#include <vector>
using namespace std;

class kmp{
private:
  string txt;
  string pattern;
  vector<int> partialTable;
public:
  kmp(string t,string p){
    txt=t;
    pattern=p;
    partialTable.assign(pattern.size(),0);
  }
  void getPartialTable(){
    
    for(int i=0;i<partialTable.size();i++){
      cout<<i<<' '<<partialTable[i]<<endl;
    }
  }
};

int main(){
  kmp stringcheck("bacbababaabcbab","abababca");
  stringcheck.getPartialTable();
  return 0;
}
