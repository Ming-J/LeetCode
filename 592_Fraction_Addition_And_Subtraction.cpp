#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
  string fractionAddition(string expression) {
    int i = 0;
    bool negative = false;
    if( checkFirstSign(expression) ){
      i++;
      negative = true;
    }
    int num = (negative)?obtainInt(expression,i)*-1:obtainInt(expression,i);
    i++;
    int dem = obtainInt(expression,i);
    while(i<expression.size()){
      obtainingFraction(expression, i, num, dem);
    }
    cout<<num<<'/'<<dem<<endl;
    return to_string(num)+'/'+to_string(dem);
  }
  
  bool checkFirstSign(string expression){
    return expression[0] == '-';
  }
  //getting the integer from string starting from position p until hits a
  //non-integer char
  int obtainInt(string expression, int &pos){
    int start = pos;
    int end=1;
    while( isdigit(expression[start+end]) ){
      end++;
    }
    pos += end;
    return stoi(expression.substr(start,end));
  }

  void obtainingFraction(string expression,
			 int &pos, int &num, int &dem){
    char sign = expression[pos];
    pos++;
    int num2 = obtainInt(expression,pos);
    pos++;
    int dem2 = obtainInt(expression,pos);
    calFraction(sign,num,dem,num2,dem2);
    reduceFraction(num,dem);
  }

  void calFraction(char sign, int &num, int &dem, int num2, int dem2){
    if(dem != dem2){
      num *= dem2;
      num2 *= dem;
      dem *= dem2;
    }
    if(sign == '-'){
      num -= num2;
    }
    if(sign == '+'){
      num += num2;
    }
  }

  void reduceFraction(int &num, int &dem){
    int divisor = gcd(abs(num),dem);
    num /= divisor;
    dem /= divisor;
  }
  
  int gcd( int a, int b){
    if(b > a){
      swap(a,b);
    }
    return (b==0)? a : gcd( b , a%b);
  }
};

int main(){
  string exp = "12/12+32/4+21/32";
  Solution test;
  test.fractionAddition(exp);
}
