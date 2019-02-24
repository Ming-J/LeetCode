#include <iostream>
#include <string>
using namespace std;

istream &read(istream &is) {
    while (!is.eof()) {
        string s;
        is >> s;
        cout << s << endl;
    }
    return is;
}

int main() { read(cin); }