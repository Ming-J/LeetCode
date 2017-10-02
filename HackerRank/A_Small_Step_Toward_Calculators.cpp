#include <iostream>
using namespace std;

int solve(string opr) {
  int a=checkint(opr[0]);
  int b=checkint(opr[2]);
  if(opr[1]=='+'){
    return a+b;
  }else{
    return a-b;
  }
}

int checkint(char i){
  return i-'0';
}

int main() {
    string opr;
    cin >> opr;
    int result = solve(opr);
    cout << result << endl;
    return 0;
}
