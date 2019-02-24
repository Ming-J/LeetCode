#include <iostream>
#include <vector>
using namespace std;
/*
    1 -> 3 5
    2 -> 1 4
    3 -> 2 4
    4 -> 1 5
    5 -> 2 3
    2 4 1 5 3
    1  3  5
*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    vector<int> line;
    line.push_back(1);
    while (line.size() < n) {
        int b = line.back();
        int first = v[b].first, second = v[b].second;
        if (v[first].first == second || v[first].second == second) {
            line.push_back(first);
            line.push_back(second);
        } else {
            line.push_back(second);
            line.push_back(first);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << line[i] << ' ';
    }
    return 0;
}
