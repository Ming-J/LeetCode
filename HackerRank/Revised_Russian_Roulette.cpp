#include <iostream>
#include <vector>
using namespace std;

int calculateMin(vector<int> doors){
  int operation = 0;
  for(int i = 0; i < doors.size(); i++){
    if( doors[i] == 1 ){
      operation++;
      doors[i] = 0;
      if( i + 1 < doors.size()){
	doors[i + 1] = 0;
      }
    }
  }
  return operation;
}
int calculateMax(vector<int> doors){
  int operation = 0;
  for(int i = 0; i < doors.size(); i++){
    if( doors[i] == 1 ){
      operation++;
      doors[i] = 0;
    }
  }
  return operation;
}


vector <int> revisedRussianRoulette(vector <int> doors) {
  // Complete this function
  vector<int> result;
  result.push_back(calculateMin(doors));
  result.push_back(calculateMax(doors));
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> doors(n);
    for(int doors_i = 0; doors_i < n; doors_i++){
       cin >> doors[doors_i];
    }
    vector <int> result = revisedRussianRoulette(doors);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
