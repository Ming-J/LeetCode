/*
  n snacks
  From 1 - n
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Snack
{
public:
  void buildTower(vector<int> skyfall)
  {
    priority_queue<int> pq;
    int prev = skyfall.size() + 1;
    for (size_t i = 0, hi = skyfall.size(); i < skyfall.size(); ++i, --hi)
    {
      pq.push(skyfall[i]);
      while (!pq.empty() && prev == pq.top() + 1 && pq.top() >= hi)
      {
        cout << pq.top() << ' ';
        pq.pop();
        --prev;
      }
      cout << "\n";
    }
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> input(n);
  for (auto &n : input)
    cin >> n;
  Snack mf;
  mf.buildTower(input);
}
