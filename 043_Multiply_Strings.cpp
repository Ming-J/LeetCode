#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

/*
      123
      456

     738
    615
   492
   56088 
*/

class Solution{
public:
  string reversenums(string s){
    int i = 0;
    int j = s.size() - 1;
    while(i < j){
      swap(s[i],s[j]);
      i++;
      j--;
    }
    return s;
  }
  
  string additions(vector<string> nums){
    string res;
    for(size_t i = 0; i < nums.size(); i++){
      char carry = '0';
      for(size_t j = 0; j < nums[i].size(); j++){
	char n1 = ( j < nums[i].size() )? nums[i][j] : '0';
	char n2 = ( j < res.size())? res[j] : '0';
	int tot = (n1-'0') + (n2-'0') + (carry-'0');
	char rem = (tot%10) + '0';
	carry = (tot/10) + '0';
	if( j < res.size() ){
	  res[j] = rem;
	}else{
	  res += rem;
	}
      }
      if( carry > '0' ) res+= carry;
    }
    return res;
  }
  
  string multiply(string num1,string num2){
    if( num1 == "0" || num2 =="0" ) return "0";
    vector<string> addition;
    for( size_t i = num1.size() - 1; i < num1.size(); --i){
      string product((num1.size()-1)-i,'0');
      char carry = '0';
      for( size_t j= num2.size() - 1; j < num2.size(); --j){
	char c1 = num1[i], c2 = num2[j];
	int sum = (c1-'0') * (c2-'0') + (carry-'0');
	char reman = sum % 10;
	carry = (sum / 10) + '0';
	product += reman+ '0';
      }
      if( carry > '0') product += carry;
      addition.push_back(product);
    }
    return reversenums(additions(addition));
  }
};

int main(){
  string s (0,'0');
  cout<<s<<endl;
  Solution test;
  cout<<test.multiply("45600","123")<<endl;
}
