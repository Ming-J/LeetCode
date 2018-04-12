#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
  if(ransom.size()>magazine.size()){
    return 0;
  }
  unordered_map<string,int> cut;
  for(int i=0;i<magazine.size();i++){
    unordered_map<string,int>:: iterator it=cut.find(magazine[i]);
    if(it==cut.end()){
      cut[magazine[i]]=0;
    }else{
      cut[magazine[i]]++;
    }
  }

  for(int i=0; i<ransom.size();i++){
    unordered_map<string,int>:: iterator it=cut.find(ransom[i]);
    if(it==cut.end()){
      return false;
    }else{
      if(it->second==0){
	cut.erase(it);
      }else{
	cut[ransom[i]]--;
      }
    }
  }
  return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
