#include <iostream>
#include <vector>
#include <utility>
using namespace std;


/*using more spaces to store the minmual number along with the value.
Time Complexity:O(1);
Space Complexity:O(N);
*/

class MinStack {
  vector< pair<int,int> > deck;
public:
  /** initialize your data structure here. */
  MinStack() {
  }
  
  void push(int x) {
    if(deck.empty()){
      deck.push_back(make_pair(x,x)); //When deck is empty, the push value will be min
    }else{//when stack is not empty, we will need to check the correct min number with previous min
      deck.push_back(make_pair(x,min(x,deck[deck.size()-1].second)));
    }
  }
    
  void pop(){
    if(!deck.empty()){
      deck.pop_back();
    }
  }
  
  int top() {
    return deck[deck.size()-1].first;
  }
    
  int getMin() {
    return deck[deck.size()-1].second;
  }
};
