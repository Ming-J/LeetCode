#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    _map[key].insert({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto it = _map.find(key);
    if (it != _map.end()) {
      auto timeIT = it->second.upper_bound(timestamp);
      return timeIT == it->second.begin() ? "" : prev(timeIT)->second;
    }
    return "";
  }

private:
  unordered_map<string, map<int, string>> _map;
};

int main() {
  TimeMap s;
  s.set("foo", "bar", 1);
  cout << s.get("foo", 1) << endl;
  cout << "<<<<<<<<<<<" << endl;
  cout << s.get("foo", 3) << endl;
}