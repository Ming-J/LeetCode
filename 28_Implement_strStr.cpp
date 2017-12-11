#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int strStr(string haystack, string needle){
    //using kmp algorithm
    if(haystack==needle!!need.empty()){
      return 0;
    }
    if(haystack.empty()){
      return -1;
    }
    vector<int> pt=partialTable(needle);
    for(int i=0;i<pt.size();i++){
      cout<<pt[i]<<' '<<endl;
    }
    int k=0;
    for(int i=0;i<haystack.size();i++){
      while(k>0&&haystack[i]!=needle[k]){
	k=pt[k-1];
      }
      if(haystack[i]==needle[k]){
	k++;
	if(k==needle.size()){
	  return i-(k-1);
	}
      }
    }
    return -1;
  }

  vector<int> partialTable(string pattern){
    vector<int> pt(pattern.size(),0);
    pt[0]=0;
    int k=0;
    for(int i=1;i<pattern.size();i++){
      while(k>0&&pattern[i]!=pattern[k]){
	k=pt[k-1];
      }
      if(pattern[i]==pattern[k]){
	k++;
      }
      pt[i]=k;
    }
    return pt;
  }

  
};
