#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  string reorganizeString(string S) {
    string ans = "";
    //Store frequencies of all characters in string
    vector<int> arr(26,0);
    for(auto c : S){
      ++arr[c-'a'];
    }
    //Inserting all character with thier frequencies into a priority_queue
    auto cmp = [](pair<char,int> lhs, pair<char,int> rhs){
      return lhs.second < rhs.second;
    };
    priority_queue< pair<char,int>, vector<pair<char,int> >, decltype(cmp) > pq(cmp);
    for(size_t i = 0; i < arr.size(); ++i){
      if(arr[i] != 0){
	pq.push(make_pair(i+'a',arr[i]));
      }
    }
    //traverse the queue
    while(pq.size()>=2){
      //Poping the top 2 element to build the string
      pair<char,int> p1 = pq.top();
      pq.pop();
      pair<char,int> p2 = pq.top();
      pq.pop();
      buildString(ans,p1,p2);
      //Adding the left over pairs back to the queue
      if(p1.second > 0) pq.push(p1);
      if(p2.second > 0) pq.push(p2);
    }
    //checking the frequency of the left over pais
    if(pq.size() == 1 && pq.top().second == 1) ans += pq.top().first;
    return (pq.size() == 1 && pq.top().second > 1)? "" : ans;
  }

private:
  //With the top two string, we add as many character as possible with the pairs
  void buildString(string &ans, pair<char,int> &p1, pair<char,int> &p2){
    while(p1.second>0&&p2.second>0){
      //Add char if it's empty, or if the char before is not the same
      if(ans.empty() || p1.first != ans[ans.size() - 1]){
	ans += p1.first;
	--p1.second;
      }
      if(ans.empty() || p2.first != ans[ans.size() - 1]){
	ans += p2.first;
	--p2.second;
      }
    }
  }
};

int main(){
  Solution test;
  cout<<test.reorganizeString("aab")<<endl;
  cout<<"0"<<endl;
}
