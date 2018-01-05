#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool isInterleave(string s1, string s2, string s3){
    if(s1.size()+s2.size()!=s3.size()){
      return false;
    }
    vector< vector<bool> > table(s2.size()+1,vector<bool> (s1.size()+1,false));

    for(int i=0;i<table.size();i++){
      for(int j=0;j<table[i].size();j++){
	if(i==0&&j==0){
	  table[i][j]=true;
	}else if(i==0&&s3[j-1]==s1[j-1]){
	  table[i][j]=table[i][j-1];
	}else if(j==0&&s3[i-1]==s2[i-1]){
	  table[i][j]=table[i-1][j];
	}else if(s2[i-1]==s3[i+j-1]&&s1[j-1]!=s3[i+j-1]){
	  table[i][j]=table[i-1][j];
	}else if(s2[i-1]!=s3[i+j-1]&&s1[j-1]==s3[i+j-1]){
	  table[i][j]=table[i][j-1];
	}else if(s2[i-1]==s3[i+j-1]&&s1[j-1]==s3[i+j-1]){
	  table[i][j]=(table[i-1][j]||table[i][j-1]);
	}
      }
    }
    return table[s2.size()][s1.size()];
  }
};

int main(){
  cout<<"hello World"<<endl;
}
