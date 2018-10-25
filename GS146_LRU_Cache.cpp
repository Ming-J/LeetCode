#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
      cap = capacity;
    }
    
    int get(int key) {
      if(hash.find(key) == hash.end()) return -1;
      else{
	pair<int,list<pair<int,int> >::iterator> reused = *hash.find(key);
	doubleList.splice(doubleList.begin(),doubleList,
			  reused.second);
	hash[key] = doubleList.begin();
	return doubleList.begin()->second;
      }
    }
    
    void put(int key, int value) {
      if(hash.find(key) == hash.end()){
	if(hash.size() >= cap){
	  pair<int,int> least = doubleList.back();
	  hash.erase(least.first);
	  doubleList.pop_back();
	}
	doubleList.insert(doubleList.begin(),{key,value});
	hash.insert(make_pair(key,doubleList.begin()));
      }else{
	pair<int, list<pair<int,int>>::iterator > reused = *hash.find(key);
	auto reusedEnd = reused.second;
	doubleList.splice(doubleList.begin(),doubleList,
			  reused.second);
	hash[key] = doubleList.begin();
	doubleList.begin()->second = value;
      }
    }

private:
  int cap;
  list< pair<int,int> > doubleList;
  unordered_map<int, list<pair<int,int> >::iterator > hash;
};
