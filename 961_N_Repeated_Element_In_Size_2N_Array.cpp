#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

#include <chrono>
class Solution {
  public:
    int repeatedNTimes(vector<int> &A) {
        // unsigned seed =
        // std::chrono::system_clock::now().time_since_epoch().count();
        mt19937 generate(8);
        uniform_int_distribution<int> dist(0, A.size() - 1);
        int a, b;
        do {
            a = dist(generate);
            b = dist(generate);
            cout << a << ' ' << b << endl;
        } while (a == b || A[a] != A[b]);
        return A[a];
    }
};