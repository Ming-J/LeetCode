/*
ID: mingjou1
LANG: C++14
TASK: transform
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void print(vector<vector<char>> p) {
  for (auto r : p) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << endl;
  }
}

vector<vector<char>> _90(vector<vector<char>> p) {
  vector<vector<char>> temp = p;
  int n = p.size();
  for (size_t i = n - 1, k = 0; i < n; --i, ++k) {
    for (size_t j = 0; j < n; ++j) {
      temp[j][k] = p[i][j];
    }
  }
  return temp;
}

vector<vector<char>> _180(vector<vector<char>> p) {
  vector<vector<char>> temp = _90(_90(p));
  return temp;
}

vector<vector<char>> _270(vector<vector<char>> p) {
  vector<vector<char>> temp = _90(_90(_90(p)));
  return temp;
}

vector<vector<char>> reflect(vector<vector<char>> p) {
  vector<vector<char>> temp = p;
  int n = p.size();
  for (int i = 0, j = n - 1; i <= j; ++i, --j) {
    for (int k = 0; k < n; ++k) {
      swap(temp[k][i], temp[k][j]);
    }
  }
  return temp;
}

bool combine(vector<vector<char>> p, vector<vector<char>> origin) {
  return _90(reflect(origin)) == p || _180(reflect(origin)) == p ||
         _270(reflect(origin)) == p;
}

void input(vector<vector<char>> &origin, vector<vector<char>> &pattern) {
  ifstream fin("transform.in");
  int n;
  fin >> n;
  cerr << "Getting n"<<n << endl;
  origin = vector<vector<char>>(n, vector<char>(n, '-'));
  pattern = vector<vector<char>>(n, vector<char>(n, '-'));
  for (int i = 0; i < n; ++i) {
    string str;
    fin >> str;
    for (size_t j = 0; j < n; ++j) {
      origin[i][j] = str[j];
    }
  }
  for (int i = 0; i < n; ++i) {
    string str;
    fin >> str;
    for (size_t j = 0; j < n; ++j) {
      pattern[i][j] = str[j];
    }
  }
}

int main() {
  vector<vector<char>> pattern, origin;
  cerr << "Program started" << endl;
  input(origin,pattern);
  cerr << "Program started oj" << endl;
  /*
  pattern = {{'@', '-', '@'}, {'-', '-', '-'}, {'@', '@', '-'}};
  pattern = {{'@', '-', '@', '-'},
             {'-', '@', '-', '-'},
             {'@', '@', '-', '-'},
             {'-', '@', '-', '-'}};
  */
  ofstream fout("transform.out");
  if (_90(origin) == pattern)
    fout << "1" << endl;
  else if (_180(origin) == pattern)
    fout << "2" << endl;
  else if (_270(origin) == pattern)
    fout << "3" << endl;
  else if (reflect(origin) == pattern)
    fout << "4" << endl;
  else if (combine(pattern, origin))
    fout << "5" << endl;
  else if (pattern == origin)
    fout << "6" << endl;
  else
    fout << "7" << endl;
  /*
  print(pattern);
  print(_90(pattern));
  cout << endl;
  print(reflect(pattern));
  cout << "Hello" << endl;*/
}
