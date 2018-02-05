#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
  vector<int> dailyTemperatures(vector<int>& temperatures){
    stack<pair<int, int> > deck;
    vector<int> res(temperatures.size(),0);
    for(int i = 0; i < temperatures.size(); i++){
      while(!deck.empty() && deck.top().first < temperatures[i]){
	res[deck.top().second] = i - deck.top().second;
	deck.pop();
      }
      deck.push({temperatures[i],i});
    }
    return res;
  }
};

int main(){
  vector<int> temps = {73,74,75,71,69,72,76,73};
  Solution test;
  vector<int> days = test.dailyTemperatures(temps);
  for( int n : days){
    cout<<n<<',';
  }
}
