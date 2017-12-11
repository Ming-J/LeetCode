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
    /*define the size of the largest prefix of pattern that is also
      the suffix, avoid backtracking*/
    partialTable[0]=0;
    int k=0;
    for(int i=1;i<partialTable.size();i++){
      while(k>0&&pattern[k]!=pattern[i]){
	k=partialTable[k-1];
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
  void search(){
    getPartialTable();
    int m=0; //Number of char matched in pattern
    for(int i=0;i<txt.size();i++){
      while(m>0&&txt[i]!=pattern[m]){
	m=partialTable[m-1];
      }
      if(txt[i]==pattern[m]){
	m++;
	if(m==pattern.size()){
	  cout<<"Match Found at position"<<i<<endl;
	  m=partialTable[m-1];
	}
      } 
    }
  }
  
};

int main(){
  kmp stringcheck("abcabdabcabdabcabcabdabc","abcabdabc");
  stringcheck.search();
  return 0;
}
