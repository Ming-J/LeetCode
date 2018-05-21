#include <iostream>
#include <regex>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

struct Contractor{
  int lineOfInt;
  vector<long> lowerBound;
  string state = "NORMAL";
  void update(int line, long lower){
    lineOfInt = line;
    lowerBound.push_back(lower);
  }
  void checkJob(vector<long> ids){
    int n = lowerBound.size();
    for(size_t i = 0; i < n; ++i){
      if(ids[i] < lowerBound[i]){
	if(n == 1){
	  state = "SHORTENED_JOB";
	}else{
	  state = "SUSPICIOUS_BATCH";
	}
	break;
      }
    }
    lowerBound.clear();
  }
};

void parseLine(string line, int n,
	       unordered_map<string,Contractor>& contractors,
	       vector<string>& frauds,long& minID){
  regex re(";");
  vector<string> part(
		      sregex_token_iterator(line.begin(),line.end(),re,-1)
		      ,{});
  string name = part[0];
  string msg = part[1];
  if(msg == "START"){
    if(contractors.find(name)==contractors.end()){
      contractors.insert(make_pair(name,Contractor()));
    }
    contractors[name].update(n,minID);
  }else{
    re=",";
    vector<string> jobStr(sregex_token_iterator(msg.begin(),msg.end(),
					      re,-1),{});
    vector<long> jobs(jobStr.size(),0);
    transform(jobStr.begin(),jobStr.end(),jobs.begin(),
	      [](string &s)->long{return stol(s);});
    sort(jobs.begin(),jobs.end());
    minID = max(minID, jobs.back());
    Contractor& c = contractors.find(name)->second;
    c.checkJob(jobs);
    if(c.state == "SHORTENED_JOB"){
      frauds.push_back(to_string(c.lineOfInt)+";"+name+";"+c.state);
    }
    if(c.state == "SUSPICIOUS_BATCH"){
      frauds.push_back(to_string(n)+";"+name+";"+c.state);
    }
  }
}


string checkFraud(vector<string>& input){
  unordered_map<string, Contractor> contractors;
  vector<string> frauds;
  long minID = LONG_MIN;
  for(size_t i = 0; i < input.size(); ++i){
    parseLine(input[i],i+1,contractors,frauds,minID);
  }
  for(auto s : frauds){
    cout<<s<<endl;
  }
  return "";
}


int main(){
  vector<string> input;
  fstream fs;
  fs.open("input.txt");
  int n;
  fs>>n;
  for(int i = 0; i < n; ++i){
    string s;
    fs>>s;
    input.push_back(s);
  }
  checkFraud(input);
}
