#include <iostream>
#include <vector>
using namespace std;

bool clock(vector<int> &degrees, int ind, int pointer) {
    if (ind == degrees.size())
        return pointer % 360 == 0 ? true : false;
    return clock(degrees, ind + 1, pointer + degrees[ind]) ||
           clock(degrees, ind + 1, pointer - degrees[ind]);
}

int main() {
    int n;
    cin >> n;
    vector<int> degrees;
    for (size_t i = 0; i < n; ++i) {
        int t;
        cin >> t;
        degrees.push_back(t);
    }
    if (clock(degrees, 0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}