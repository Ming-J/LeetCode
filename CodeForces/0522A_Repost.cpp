#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Jokes {
public:
  Jokes() { degree.insert({"POLYCARP", 1}); }

  void insert(string n1, string n2) {
    transform(n1.begin(), n1.end(), n1.begin(), ::toupper);
    transform(n2.begin(), n2.end(), n2.begin(), ::toupper);
    int cur_degree = degree[n2];
    auto n1_it = degree.find(n1);
    if (n1_it == degree.end()) {
      degree.insert({n1, cur_degree + 1});
    } else {
      n1_it->second = max(n1_it->second, cur_degree + 1);
    }
    highDegree = max(highDegree, degree[n1]);
  }
  int getHighestDegree() { return highDegree; }

private:
  unordered_map<string, int> degree;
  int highDegree = 0;
};

int main() {
  int n;
  cin >> n;
  Jokes temp;
  for (int i = 0; i < n; ++i) {
    string n1, rp, n2;
    cin >> n1 >> rp >> n2;
    temp.insert(n1, n2);
  }
  cout << temp.getHighestDegree() << endl;
}
