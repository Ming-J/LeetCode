#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<int> p2(30, 0);
    p2[0] = 1;
    for (size_t i = 1; i < p2.size(); ++i)
        p2[i] = p2[i - 1] * 2;
    int n = 3, k = 7;
    cin >> n >> k;
    bitset<30> b1(n);
    multiset<int, greater<int>> m_s;
    for (size_t i = 0; i < b1.size(); ++i) {
        if (b1[i] == 1) {
            m_s.insert(p2[i]);
        }
    }
    while (m_s.size() < k && *(m_s.begin()) != 1) {
        int half = *(m_s.begin()) / 2;
        m_s.erase(m_s.begin());
        m_s.insert(half);
        m_s.insert(half);
    }
    if (m_s.size() == k) {
        cout << "YES" << endl;
        for (auto i : m_s)
            cout << i << ' ';
    } else {
        cout << "NO" << endl;
    }
    return 0;
}