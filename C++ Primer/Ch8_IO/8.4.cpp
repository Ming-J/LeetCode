#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> list;
    ifstream inf("ch8.md");
    string s;
    while (getline(inf, s)) {
        list.push_back(s);
    }
    for (auto s : list) {
        cout << s << endl;
    }
}