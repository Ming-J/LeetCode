#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y != X) {
            if (Y < X)
                Y += 1;
            else
                Y = (Y % 2 == 0) ? Y / 2 : Y + 1;
            ans++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    cout << s.brokenCalc(3, 10);
};