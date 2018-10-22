#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int compress(vector<char> &chars) {
    if (chars.size() < 2)
      return chars.size();
    int modifyIndex = 0;
    int currentIndex = 0;
    while (currentIndex < chars.size()) {
      char currentChar = chars[currentIndex];
      int currentCount = 0;
      // Looking forward until a different char
      while (currentIndex < chars.size() &&
             currentChar == chars[currentIndex]) {
        ++currentIndex;
        ++currentCount;
      }
      // Compressing the string
      chars[modifyIndex++] = currentChar;
      if (currentCount > 1) {
        for (char c : to_string(currentCount)) {
          chars[modifyIndex++] = c;
        }
      }
    }
    return modifyIndex;
  }
};
