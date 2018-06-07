#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache{
public:
  LRUCache(int capacity):cacheLength(capacity){}
  int get(int key){
    if(pointer.find(key)!=pointer.end()){
      //moving the cache to the front
      list<pair<int,int> >::iterator cachePointer = pointer.find(key)->second;
      int value = cachePointer->second;
      cache.splice(cache.begin(),cache,cachePointer);
      //list<pair<int,int> >::iterator it = cache.insert(cache.begin(),make_pair(key,value));
      pointer[key] = cache.begin();
      return value;
    }
    //key not existed
    return -1;
  }
  void put(int key, int value){
    //checking if key is in cache already
    if(pointer.find(key)==pointer.end()){
      //not in cache
      list<pair<int,int> >::iterator it= cache.insert(cache.begin(),make_pair(key,value)); 
      pointer.insert(make_pair(key,it));
      //if the size of the cache is too big
      if(cache.size() > cacheLength){
	list<pair<int,int> >::iterator back = cache.end();
	--back;
	pointer.erase(back->first);
	cache.pop_back();
      }
    }else{
      //If the key is in the cache, we moved the element to the front of the list
      list<pair<int,int> >::iterator used = pointer[key];
      used->second = value;
      cache.splice(cache.begin(),cache,used);
      pointer[key] = cache.begin();
    }
  }

private:
  int cacheLength;
  list< pair<int,int> > cache;
  unordered_map<int,list<pair<int,int> >::iterator> pointer;
};
