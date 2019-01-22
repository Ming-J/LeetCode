#include <iostream>
#include <vector>
using namespace std;

long m = 1E9 + 7;

class Tetrahedron {
  public:
    Tetrahedron(long f) {
        vector<vector<long>> dp(2, vector<long>(4, 0));
        dp[0][3] = 1;
        for (int i = 1; i <= f; ++i) {
            for (size_t j = 0; j < dp[1].size(); ++j) {
                long a = (j != 0) ? dp[0][0] : 0;
                long b = (j != 1) ? dp[0][1] : 0;
                long c = (j != 2) ? dp[0][2] : 0;
                long d = (j != 3) ? dp[0][3] : 0;
                dp[1][j] = (((((a + b) % m) + c) % m) + d) % m;
            }
            dp[0] = dp[1];
        }
        ways = dp[1][3];
    }
    long getWay() { return ways; }

  private:
    long ways;
};

int main() {
    long n;
    cin >> n;
    Tetrahedron t(n);
    cout << t.getWay() << endl;
}