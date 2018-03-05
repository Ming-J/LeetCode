#include <iostream>
using namepsace std;

class Solution {
public:
  vector<int> constructRectangle(int area) {
    int length = sqrt(area), width = sqrt(area);
    while(length * width != area){
      length++;
      width = area / length;
    }
    return {length, width};
  }
};
