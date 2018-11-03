#include <iostream>
#include <set>
using namespace std;


class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
      auto iter = time.lower_bound({start,end});
      if(iter!=time.end()&&iter->first<end) return false;
      if(iter!=time.begin()&&(--iter)->second > start) return false;
      time.insert({start,end});
      return true;
    }


private:
  set< pair<int,int> > time;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
