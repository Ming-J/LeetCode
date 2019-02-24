#include <iostream>
#include <string>
#define MOD 998244353;
using namespace std;

int check(string str, int n) {
    int prefix = 1;
    for (size_t i = 1; i < str.size() && str[i] == str.front(); i++)
        prefix++;
    int sufix = 1;
    for (size_t i = str.size() - 2; i < str.size() && str[i] == str.back(); --i)
        ++sufix;
    long long int ans;
    if (n == prefix) {
        ans = n * (n - 1) / 2 + n;
        ans %= MOD;
    } else if (str.front() == str.back()) {
        ans = (prefix + 1LL) * (sufix + 1LL) % MOD;
    } else {
        ans = (prefix + sufix + 1LL) % MOD;
    }
    cout << ans << endl;
    return 0;
}

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    check(s, n);
}