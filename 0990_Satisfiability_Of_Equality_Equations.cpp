#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  public:
    bool equationsPossible(vector<string> &equations) {
        vector<int> id(26);
        iota(id.begin(), id.end(), 0);
        for (string e : equations) {
            if (e[1] == '=') {
                int x = e[0] - 'a';
                int y = e[3] - 'a';
                qunion(id, x, y);
            }
        }
        for (string e : equations) {
            if (e[1] == '!') {
                int x = e[0] - 'a';
                int y = e[3] - 'a';
                if (Findroot(id, y) == Findroot(id, x))
                    return false;
            }
        }
        return true;
    }

  private:
    void qunion(vector<int> &A, int a, int b) {
        int a_root = Findroot(A, a);
        int b_root = Findroot(A, b);
        A[a_root] = b_root;
    }

    int Findroot(vector<int> &A, int a) {
        if (A[a] == a)
            return a;
        return Findroot(A, A[a]);
    }
};

int main() { cout << "dsa" << endl; };