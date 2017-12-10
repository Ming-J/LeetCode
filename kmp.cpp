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
    partialTable[0]=0;
    int k=0;
    for(int i=1;i<partialTable.size();i++){
      //int k = partialTable[i-1];
      cout<<k<<' '<<i<<endl;
      while(k>0&&pattern[k]!=pattern[i]){
	k=partialTable[k-1];
	cout<<"K::"<<k<<endl;
      }
      if(pattern[k]==pattern[i]){
	k++;
      }
      partialTable[i]=k;
    }
    for(int i=0;i<partialTable.size();i++){
      cout<<pattern[i];
    }
    cout<<endl;
    for(int i=0;i<partialTable.size();i++){
      cout<<partialTable[i];
    }
  }
};

int main(){
  kmp stringcheck("bacbababaabcbab","abababca");
  stringcheck.getPartialTable();
  return 0;
}
