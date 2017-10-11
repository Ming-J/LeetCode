#include <iostream>
#include <vector>
#include <utility>
#include <climit>
using namespace std;

class MinStack {
  vector< pair<int,long int> > deck;
  int small;
public:
    /** initialize your data structure here. */
    MinStack() {
      small=INT_MAX;
    }
    
    void push(int x) {
      small=min(small,x);
      deck.push_back(make_pair(x,small));
    }
    
  void pop(){
    if(deck)
    deck.pop_back();
    if(deck.empty()){
      small=INT_MAX;
    }
  }
    
    int top() {
      return deck[deck.size()-1].first;
    }
    
    int getMin() {
      return deck[deck.size()-1].second;
    }
};
