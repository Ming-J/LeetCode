#include <iostream>
using namespace std;

class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n == 1)
            return true;
        for (int i = 0; i < 30; ++i) {
            if (n == (2 << i))
                return true;
        }
        return false;
    }
};

int main() {
    for (int i = 0; i < 32; ++i) {
        cout << (0 << i) << endl;
    }
}