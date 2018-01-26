#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord,
		   string endWord,
		   vector<string>& wordList)
  {
    int length = 0;
    deque<string> deck;
    deck.push_back(beginWord);
    while( !deck.empty()){
      int n = deck.size();
      length++;
      for(int i = 0; i < n; i++){
	string cur = deck.front();
	//cout<<cur<<endl;
	if(cur == endWord){
	  return length;
	}
	deck.pop_front();
	for(int j = 0; j < wordList.size(); j++){
	  if(checkTransform(cur,wordList[j])){
	    //cout<<cur<<':'<<wordList[j]<<endl;
	    deck.push_back(wordList[j]);
	    wordList[j] = "";
	  }
	}
      }
    }
    return -1;
  }

  bool checkTransform(string w1, string w2){
    if(w1.size() != w2.size()){
      return false;
    }
    int diff=0;
    for( int i = 0 ; i < w1.size() ; i++){
      if(w1[i] != w2[i]){
	diff++;
      }
    }
    return (diff==1) ? true : false;
  }
};

int main(){
  string begin = "hit";
  string end = "cog";
  vector<string> arr = {"hot","dot","dog","lot","log","cog"};
  Solution test;
  cout<<test.ladderLength(begin,end,arr);
}
