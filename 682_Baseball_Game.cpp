#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int calPoints(vector<string>& ops){
    vector<int> scores;
    int sum=0;
    for(int i=0;i<ops.size();i++){
      if(ops[i]=="C"){
	sum-=scores.back();
	scores.pop_back();
      }else if(ops[i]=="+"){
	int innScore=scores[scores.size()-2]+scores.back();
	scores.push_back(innScore);
	sum+=innScore;
      }else if(ops[i]=="D"){
	int innScore=scores.back()*2;
	scores.push_back(innScore);
	sum+=innScore;
      }else{
	int innScore=stoi(ops[i]);
	scores.push_back(innScore);
	sum+=innScore;
      }
    }
    return sum;
  }
};
